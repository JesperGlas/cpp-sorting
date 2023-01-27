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
