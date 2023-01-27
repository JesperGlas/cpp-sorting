#include "LinkedList.hpp"

void LinkedList::append(int value)
{
	Node *node = new Node(value);
	if (this->_size == 0)
	{
		this->_head = node;
		this->_tail = node;
	}
	else
	{
		node->_prev = this->_tail;
		this->_tail->_next = node;
		this->_tail = node;
	}
	this->_size++;
	return;
}

void LinkedList::push(int value)
{
	if (this->_size == 0)
		this->append(value);
	else
	{
		Node *node = new Node(value);
		node->_next = this->_head;
		this->_head->_prev = node;
		this->_head = node;
		this->_size++;
	}
}

int LinkedList::pop()
{
	// check that list contains elements
	if (this->_size < 1)
	{
		std::clog << "Warning! Popping from empty list!" << std::endl;
		return -1;
	}
	// update list
	Node *tmp = this->_head;
	this->_head = tmp->_next;
	this->_head->_prev = nullptr;
	this->_size--;

	// clean up memory
	int value = tmp->_data;
	delete tmp;

	return value;
}

int LinkedList::pull()
{
	// check that list contains elements
	if (this->_size < 1)
	{
		std::clog << "Warning! Pulling from empty list!" << std::endl;
		return -1;
	}
	// update list
	Node *tmp = this->_tail;
	this->_tail;
	return -1;
}

void LinkedList::swap(Node *a, Node *b)
{
	// insert a
	Node *a_prev = a->_prev;
	if (b->_prev == nullptr)
		this->_head = a;
	else
		b->_prev->_next = a;
	a->_prev = b->_prev;
	
	Node *a_next = a->_next;
	if (b->_next == nullptr)
		this->_tail = a;
	else
		b->_next->_prev = a;
	a->_next = b->_next;
	
	// insert b
	if (a_prev == nullptr)
		this->_head = b;
	else
		a_prev->_next = b;
	b->_prev = a_prev;

	if (a_next == nullptr)
		this->_tail = b;
	else
		a_next->_prev = b;
	b->_next = a_next;

	return;
}
Node * LinkedList::getNode(size_t index)
{
	if (index >= this->_size)
	{
		return this->_tail;
	}
	Node *current = this->_head;
	for (size_t i = 0; i < index; i++)
		current = current->_next;
	return current;
}

int LinkedList::sort_ins()
{
	Node *current = this->_head;
	while (current != this->_tail)
	{
		if (current->_data <= current->_next->_data)
		{
			current = current->_next;
		}
		else
		{
			Node *a = current;
			Node *b = current->_next;
			this->swap(a, b);
			if (b == this->_head)
				current = b;
			else
				current = b->_prev;
		}
	}
	return 1;
}

std::ostream & operator<<(std::ostream &os, const LinkedList &list)
{
	if (list._head != nullptr)
	{
		// print head as current
		Node *current = list._head;
		std::cout << "[ " << (*current);
		
		// print additional nodes
		while (current->_next != nullptr)
		{
			current = current->_next;
			std::cout << ", " << (*current);
		}
		std::cout << "]";
	}
	return os;
}

