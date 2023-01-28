#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__

#include <iostream>
#include "Node.hpp"

class LinkedList
{
private:
	Node *_head;
	Node *_tail;
	Node *_mid;
	size_t _size;

	Node *atIndex(size_t index);
	void swap(Node *a, Node *b);
public:	
	LinkedList() : _head(nullptr), _tail(nullptr), _mid(nullptr), _size(0) {};
	~LinkedList();
	
	// core
	int head();
	int tail();
	int mid();
	int get(size_t index);
	bool isSorted();
	void append(int value);
	void append(int values[], size_t n);
	void push(int value);
	void push(int values[], size_t n);
	void insert(int value, size_t index);
	int pop();
	int popTail();
	int pop(size_t index);
	void split(LinkedList &head, LinkedList &tail);

	// sorting
	int sort_ins();

	// simple
	inline size_t size() {return this->_size;};
	inline void swap(size_t i, size_t j)
	{
		Node *a = this->atIndex(i);
		Node *b = this->atIndex(j);
		this->swap(a, b);
		return;
	};

	friend std::ostream & operator<<(std::ostream &os, const LinkedList &list);
};

std::ostream & operator<<(std::ostream &os, const LinkedList &list);
#endif
