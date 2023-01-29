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

TEST(LinkedListTests, indexOperatorTest)
{
	// init list
	LinkedList lst = LinkedList();
	size_t n = 5;
	int values[n] = {0, 1, 2, 3, 4};
	lst.append(values, n);
	EXPECT_EQ(lst.size(), 5);

	// get values
	EXPECT_EQ(lst[0], 0);
	EXPECT_EQ(lst[4], 4);
	
	// change values
	int tmp = lst[0];
	lst[0] = lst[4];
	lst[4] = lst[2];
	lst[2] = tmp;
	// [4, 1, 0, 3, 2]
	EXPECT_EQ(lst.head(), 4);
	EXPECT_EQ(lst.tail(), 2);
	EXPECT_EQ(lst.mid(), 0);
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

TEST(LinkedListTests, isSortedTest)
{
	// init list
	LinkedList lst = LinkedList();
	size_t n = 5;
	int values[n] = {1, 2, 4, 6, 3};
	lst.append(values, n);

	// test list is not sorted
	EXPECT_FALSE(lst.isSorted());

	// test list sorted
	lst.popTail();
	// [1, 2, 4, 6]
	EXPECT_TRUE(lst.isSorted());
}

TEST(LinkedListTests, sortInsertionTest)
{
	// init list
	LinkedList lst = LinkedList();
	size_t n = 10;
	int values[n] = {3, 2, 5, 1, 7, 0, 8, 9, 4, 6};
	lst.append(values, n);

	// check that list is not sorted
	EXPECT_FALSE(lst.isSorted());
	
	// sort list
	lst.sort_ins();

	// make sure list is sorted using member function
	EXPECT_TRUE(lst.isSorted());

	// make sure following values are equal or lower
	for (size_t i = 1; i < lst.size(); i++)
		EXPECT_TRUE(lst.get(i-1) <= lst.get(i));	
}

TEST(LinkedListTests, midNodeAppendPopTailTest)
{
	// init list
	LinkedList lst = LinkedList();
	lst.append(3);
	// [-3-]
	EXPECT_EQ(lst.mid(), 3);
	lst.append(4);
	// [-3-, 4]
	EXPECT_EQ(lst.mid(), 3);
	lst.append(5);
	// [3, -4-, 5]
	EXPECT_EQ(lst.mid(), 4);
	lst.append(6);
	// [3, -4-, 5, 6]
	EXPECT_EQ(lst.mid(), 4);
	lst.append(7);
	// [3, 4, -5-, 6, 7]
	EXPECT_EQ(lst.mid(), 5);
	lst.popTail();
	// [3, -4-, 5, 6]
	EXPECT_EQ(lst.mid(), 4);
	lst.popTail();
	// [3, -4-, 5]
	EXPECT_EQ(lst.mid(), 4);
	lst.popTail();
	// [-3-, 4]
	EXPECT_EQ(lst.mid(), 3);
	lst.popTail();
	// [-3-]
	EXPECT_EQ(lst.mid(), 3);
	// [ ]
	lst.popTail();
	EXPECT_EQ(lst.mid(), -1);
}

TEST(LinkedListTests, midNodePushPopTest)
{
	// init list
	LinkedList lst = LinkedList();
	lst.push(7);
	// [-7-]
	EXPECT_EQ(lst.mid(), 7);
	lst.push(6);
	// [-6-, 7]
	EXPECT_EQ(lst.mid(), 6);
	lst.push(5);
	// [5, -6-, 7]
	EXPECT_EQ(lst.mid(), 6);
	lst.push(4);
	// [4, -5-, 6, 7]
	EXPECT_EQ(lst.mid(), 5);
	lst.push(3);
	// [3, 4, -5-, 6, 7]
	EXPECT_EQ(lst.mid(), 5);
	lst.push(2);
	// [2, 3, -4-, 5, 6, 7]
	EXPECT_EQ(lst.mid(), 4);
	lst.push(1);
	// [1, 2, 3, -4-, 5, 6, 7]
	EXPECT_EQ(lst.mid(), 4);
	lst.pop();
	// [2, 3, -4-, 5, 6, 7]
	EXPECT_EQ(lst.mid(), 4);
	lst.pop();
	// [3, 4, -5-, 6, 7]
	EXPECT_EQ(lst.mid(), 5);
	lst.pop();
	// [4, -5-, 6, 7]
	EXPECT_EQ(lst.mid(), 5);
	lst.pop();
	// [5, -6-, 7]
	EXPECT_EQ(lst.mid(), 6);
	lst.pop();
	// [-6-, 7]
	EXPECT_EQ(lst.mid(), 6);
	lst.pop();
	// [-7-]
	EXPECT_EQ(lst.mid(), 7);
	lst.pop();
	// [ ]
	EXPECT_EQ(lst.mid(), -1);
}

TEST(LinkedListTests, midNodeExtTest)
{
	// init list
	LinkedList lst = LinkedList();
	lst.append(5);
	// [-5-]
	EXPECT_EQ(lst.mid(), 5);

	size_t n = 5;
	int appValues[n] = {6, 7, 8, 9, 10};
	int pushValues[n] = {0, 1, 2, 3, 4};
	lst.append(appValues, n);
	// [5, 6, -7-, 8, 9, 10]
	EXPECT_EQ(lst.size(), 6);
	EXPECT_EQ(lst.mid(), 7);
	lst.push(pushValues, n);
	// [0, 1, 2, 3, 4, -5-, 6, 7, 8, 9, 10]
	EXPECT_EQ(lst.size(), 11);
	EXPECT_EQ(lst.mid(), 5);
	EXPECT_EQ(lst.pop(5), 5);
	// [0, 1, 2, 3, -4-, 6, 7, 8, 9, 10]
	EXPECT_EQ(lst.mid(), 4);
}

TEST(LinkedListTests, insertTest)
{
	// init list
	LinkedList lst = LinkedList();
	size_t n = 5;
	int values[n] = {1, 2, 3, 4, 5};

	lst.append(values, n);
	// [1, 2, -3-, 4, 5]
	EXPECT_EQ(lst.head(), 1);
	EXPECT_EQ(lst.mid(), 3);
	EXPECT_EQ(lst.tail(), 5);

	lst.insert(0, 0);
	// [0, 1, -2-, 3, 4, 5]
	EXPECT_EQ(lst.head(), 0);
	EXPECT_EQ(lst.tail(), 5);
	EXPECT_EQ(lst.mid(), 2);
	
	lst.insert(6, 6);
	// [0, 1, 2, -3-, 4, 5, 6]
	EXPECT_EQ(lst.head(), 0);
	EXPECT_EQ(lst.tail(), 6);
	EXPECT_EQ(lst.mid(), 3);
}

TEST(LinkedListTests, splitTest)
{
	// init list
	LinkedList lst = LinkedList();
	size_t n = 10;
	int values[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	lst.append(values, n);
	// [0, 1, 2, 3, -4-, 5, 6, 7, 8, 9]
	EXPECT_EQ(lst.size(), 10);

	// split
	LinkedList head = LinkedList();
	LinkedList tail = LinkedList();
	lst.split(head, tail);
	// head = [0, 1, -2-, 3, 4]
	EXPECT_EQ(head.size(), 5);
	EXPECT_EQ(head.head(), 0);
	EXPECT_EQ(head.tail(), 4);
	EXPECT_EQ(head.mid(), 2);
	// tail = [5, 6, -7-, 8, 9]
	EXPECT_EQ(tail.size(), 5);
	EXPECT_EQ(tail.head(), 5);
	EXPECT_EQ(tail.tail(), 9);
	EXPECT_EQ(tail.mid(), 7);
}
