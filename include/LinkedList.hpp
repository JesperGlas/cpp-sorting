#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__

#include <iostream>
#include "Node.hpp"

class LinkedList
{
private:
	Node *_head;
	Node *_tail;
	size_t _size;
public:	
	LinkedList() : _head(nullptr), _tail(nullptr), _size(0) {};
	void append(int value);
	void push(int value);
	int pop();
	int pull();
	void swap(Node *a, Node *b);
	Node *getNode(size_t index);

	int sort_ins();

	inline size_t getSize() {return this->_size;};
	inline void swapAtIdx(size_t i, size_t j)
	{
		Node *a = this->getNode(i);
		Node *b = this->getNode(j);
		this->swap(a, b);
		return;
	};

	friend std::ostream & operator<<(std::ostream &os, const LinkedList &list);
};

std::ostream & operator<<(std::ostream &os, const LinkedList &list);
#endif
