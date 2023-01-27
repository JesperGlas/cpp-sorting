#ifndef __NODE_HPP__
#define __NODE_HPP__

#include <iostream>

class Node
{
public:
	int _data;
	Node *_next;
	Node *_prev;
public:
	Node(int data) : _data(data), _next(nullptr), _prev(nullptr) {};
	~Node()
	{
		if (this->_next != nullptr)
			this->_next->_prev = this->_prev;
		if (this->_prev != nullptr)
			this->_prev->_next = this->_next;
	}
};

inline std::ostream & operator<<(std::ostream &os, const Node &node)
{
	os << node._data;
	return os;
}

#endif
