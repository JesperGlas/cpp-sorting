#include "gtest/gtest.h"
#include "LinkedList.hpp"

TEST(LinkedListTests, initTests)
{
	EXPECT_EQ(true, true);
}

TEST(LinkedListTests, defConstructorTest)
{
	// check init
	LinkedList lst = LinkedList();
	EXPECT_EQ(lst.size(), 0);
}

TEST(LinkedListTests, appendTest)
{
	// init list
	LinkedList lst = LinkedList();
	EXPECT_EQ(lst.size(), 0);

	// append 1 elem
	lst.append(5);
	EXPECT_EQ(lst.size(), 1);
	EXPECT_EQ(lst.head(), 5);
	EXPECT_EQ(lst.tail(), 5);

	// append 2nd element
	lst.append(3);
	EXPECT_EQ(lst.size(), 2);
	EXPECT_EQ(lst.head(), 5);
	EXPECT_EQ(lst.tail(), 3);
}

TEST(LinkedListTests, appendMultipleTest)
{
	// init list
	LinkedList lst = LinkedList();
	EXPECT_EQ(lst.size(), 0);

	// append single
	lst.append(100);
	// [ 100 ]

	// append multiple
	size_t size = 5;
	int values[size] = {1, 2, 3, 4, 5};
	lst.append(values, size);
	// [100, 1, 2, 3, 4, 5]
	EXPECT_EQ(lst.size(), size+1);
	EXPECT_EQ(lst.head(), 100);
	EXPECT_EQ(lst.tail(), 5);
}

TEST(LinkedListTests, pushTest)
{
	// init list
	LinkedList lst = LinkedList();
	EXPECT_EQ(lst.size(), 0);

	// push one element
	lst.push(5);
	EXPECT_EQ(lst.size(), 1);
	EXPECT_EQ(lst.head(), 5);
	EXPECT_EQ(lst.tail(), 5);

	// push second element
	lst.push(3);
	EXPECT_EQ(lst.size(), 2);
	EXPECT_EQ(lst.head(), 3);
	EXPECT_EQ(lst.tail(), 5);
}

TEST(LinkedListTests, pushMultipleTest)
{
	LinkedList lst = LinkedList();
	EXPECT_EQ(lst.size(), 0);

	// push single
	lst.push(100);
	// [ 100 ]

	// push multiple
	size_t size = 5;
	int values[size] = {1, 2, 3, 4, 5};
	lst.push(values, size);
	// [1, 2, 3, 4, 5, 100]
	EXPECT_EQ(lst.size(), size+1);
	EXPECT_EQ(lst.head(), 1);
	EXPECT_EQ(lst.tail(), 100);
}

TEST(LinkedListTests, popTests)
{
	// init lst
	LinkedList lst = LinkedList();
	size_t n = 5;
	int values[n] = {1, 2, 3, 4, 5};
	lst.append(values, n);

	// pop 
	EXPECT_EQ(lst.pop(), 1);
	EXPECT_EQ(lst.size(), 4);
	// [2, 3, 4, 5]
	EXPECT_EQ(lst.pop(1), 3);
	EXPECT_EQ(lst.size(), 3);
	// [2, 4, 5]
	EXPECT_EQ(lst.popTail(), 5);
	EXPECT_EQ(lst.size(), 2);
	// [2, 4]
	EXPECT_EQ(lst.pop(), 2);
	// [4]
	EXPECT_EQ(lst.pop(), 4);
	EXPECT_EQ(lst.size(), 0);

	// test pop empty
	EXPECT_EQ(lst.pop(), -1);
	EXPECT_EQ(lst.popTail(), -1);
	EXPECT_EQ(lst.pop(1), -1);
}

TEST(LinkedListTests, getTest)
{
	// init list
	LinkedList lst = LinkedList();
	size_t n = 5;
	int values[n] = {1, 2, 3, 4, 5};
	lst.append(values, n);

	// get
	EXPECT_EQ(lst.get(0), 1);
	EXPECT_EQ(lst.get(4), 5);
	EXPECT_EQ(lst.get(2), 3);
}

TEST(LinkedListTests, sortInsertionTest)
{
	// init list
	LinkedList lst = LinkedList();
	size_t n = 10;
	int values[n] = {3, 2, 5, 1, 7, 0, 8, 9, 4, 6};
	lst.append(values, n);
	
	// sort list
	lst.sort_ins();

	// make sure following values are equal or lower
	for (size_t i = 1; i < lst.size(); i++)
		EXPECT_TRUE(lst.get(i-1) <= lst.get(i));	
}

