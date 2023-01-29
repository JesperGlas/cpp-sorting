#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__

#include <iostream>
#include "Node.hpp"

class LinkedList
{
private:
	// holds the first node of the list
	Node *_head;
	// holds the last node of the list
	Node *_tail;
	// holds the middle node of list (first one when two nodes are in the middle)
	Node *_mid;
	// holds the number of nodes in the list
	size_t _size;

	/* ### PRIVATE FUNCTIONS ### */

	/**
	 * Function that fetches the node at the index wihout altering the list.
	 * 	Handles out of bounds index by getting HEAD, TAIL of list.
	 *
	 * Args:
	 * 	index (size_t) - the index of the node
	 *
	 * Return:
	 * 	(Node*) - Node at index
	 * 		negative index returns HEAD
	 * 		out-of-bounds index returns TAIL
	 * */
	Node *atIndex(size_t index);

	/**
	 * Function swaps the place of two nodes in list.
	 * 	NOTE! Actually swaps nodes and not just their values.
	 *
	 * Args:
	 * 	a (Node*) - one of the nodes
	 * 	b (Node*) - the other node
	 * */
	void swap(Node *a, Node *b);
public:	
	LinkedList() : _head(nullptr), _tail(nullptr), _mid(nullptr), _size(0) {};
	~LinkedList();
	
	/* # CORE # */

	/**
	 * Function returns the value of the first node in list without altering the list.
	 *
	 * Return:
	 * 	(int) - value of first node
	 * */
	int head();

	/**
	 * Function returns the value of the last node in list without altering the list.
	 *
	 * Return:
	 * 	(int) - value of the last node
	 * */
	int tail();

	/**
	 * Function returns the value of the middle node in the list without altering the list.
	 *
	 * Return:
	 * 	(int) - value of the middle node
	 * */
	int mid();

	/**
	 * Function gets the value of the node at specified index in list without altering list.
	 * 	Handles out of bounds by returning HEAD or TAIL of list.
	 *
	 * Args:
	 * 	index (size_t) - index of value
	 *
	 * Return:
	 * 	(int) - value of node at index
	 * */
	int get(size_t index);

	/**
	 * Function checks if the list is sorted.
	 *
	 * Return:
	 * 	(bool) - true if list is sorted by value, false if not
	 * */
	bool isSorted();

	/**
	 * Adds a new node at the end of the list with the specified value.
	 *
	 * Args:
	 * 	value (int) - value of new node
	 * */
	void append(int value);

	/**
	 * Adds all the values of an array at the end of the list.
	 *
	 * Args:
	 * 	values (int[]) - the values
	 * 	n (size_t) - amount of new nodes
	 * */
	void append(int values[], size_t n);

	/**
	 * Adds a new node at the start of the list.
	 *
	 * Args:
	 * 	value (int) - the value of the new node
	 * */
	void push(int value);

	/**
	 * Adds all the values of the array at the start of the list.
	 *
	 * Args:
	 * 	values (int[]) - the values
	 * 	n (size_t) - amount of new node
	 * */
	void push(int values[], size_t n);

	/**
	 * Adds a new node at the specified index.
	 *
	 * Args:
	 *	value (int) - the value of the new node
	 *	index (size_t) - the index of the new node
	 * */
	void insert(int value, size_t index);

	/**
	 * Removes the first node of the list and returns its value.
	 *
	 * Return:
	 *	(int) - value of the node
	 * */
	int pop();

	/**
	 * Removes the last node of the list and returns its value.
	 *
	 * Return:
	 * 	(int) - value of the node
	 * */
	int popTail();

	/**
	 * Removes the node at the specified index and returns its value.
	 *
	 * Args:
	 * 	index (size_t) - the index of the node
	 *
	 * Return:
	 * 	(int) - the value of the node
	 * */
	int pop(size_t index);

	/**
	 * Splits the list in half. Uses the original lists nodes.
	 * 	Warning! Modifying the original list will result in undefined behaviour.
	 *
	 * Args:
	 * 	head (LinkedList &) - instance to hold the first half of the list
	 * 	tail (LinkedList &) - instance to hold the last half of the list
	 * */
	void split(LinkedList &head, LinkedList &tail);

	/**
	 * Overloading index operator[] for linked list. Returns value of node at index.
	 * 	Functions as both getter and setter for the value.
	 * 	Throws exception when index is out of bounds.
	 *
	 * Args:
	 * 	index (size_t) - index of the node
	 *
	 * Return:
	 * 	(int &) - value of node at index
	 * */
	int & operator[](size_t index);

	/* # SORTING # */

	/**
	 * Function sorts the linked list using insertion sort.
	 *
	 * Return:
	 * 	(int) - count of loops required to sort the list.
	 * */
	int sort_ins();

	/* # INLINE # */

	/**
	 * Returns the size, amount of nodes, of the list.
	 *
	 * Return:
	 * 	(size_t) - the size of the list
	 * */
	inline size_t size() {return this->_size;};

	/**
	 * Swaps the nodes at the specified indices.
	 *
	 * Args:
	 * 	i (size_t) - index of one node
	 * 	j (size_t) - index of the other node
	 * */
	inline void swap(size_t i, size_t j)
	{
		Node *a = this->atIndex(i);
		Node *b = this->atIndex(j);
		this->swap(a, b);
		return;
	};

	/* # FRIEND # */
	friend std::ostream & operator<<(std::ostream &os, const LinkedList &list);
};

/**
 * Overload of operator<<. Used to print the list.
 * */
std::ostream & operator<<(std::ostream &os, const LinkedList &list);

#endif
