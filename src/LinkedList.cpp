#include "LinkedList.hpp"

/* ### CORE ### */
LinkedList::~LinkedList()
{
	Node *current = this->_head;
	Node *next = nullptr;
	while (current != nullptr)
	{
		next = current->_next;
		delete current;
		current = next;
	}
}

/* ### PRIVATE ### */
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

Node * LinkedList::atIndex(size_t index)
{
	if (index < 0 || index >= this->_size)
	{
		std::cerr << "[Index Error]: Index out of bounds!" << std::endl;
		exit(EXIT_FAILURE);
	}

	Node *current = this->_head;
	for (size_t i = 0; i < this->_size; i++)
		current = current->_next;

	return current;
}

/* ### PUBLIC ### */
int LinkedList::head()
{
	if (this->_head == nullptr)
	{
		std::clog << "Warning! Requesting HEAD of empty list, returning -1." << std::endl;
		return -1;
	}
	return this->_head->_data;
}

int LinkedList::tail()
{
	if (this->_tail == nullptr)
	{
		std::clog << "Warning! Requesting TAIL of empty list, returning -1." << std::endl;
		return -1;
	}
	return this->_tail->_data;
}

int LinkedList::mid()
{
	if (this->_mid == nullptr)
	{
		std::clog << "Warning! Requesting MID of empty list, returning -1." << std::endl;
		return -1;
	}
	return this->_mid->_data;
}

int LinkedList::get(size_t index)
{
	// handle empty list
	if (this->_size <= 0)
	{
		std::clog << "Warning! Requesting element of empty list, returning -1." << std::endl;
		return -1;
	}

	// handle negative index
	if (index < 0)
	{
		std::clog << "Warning! Negative index, returning HEAD." << std::endl;
		return this->head();
	}

	// handle index out of bounds
	if (index >= this->_size)
	{
		std::clog << "Warning! Index out of bounds, returning TAIL." << std::endl;
		return this->tail();
	}

	Node *current = this->_head;
	for (size_t i = 0; i < index; i++)
		current = current->_next;

	return current->_data;
}

bool LinkedList::isSorted()
{
	for (size_t i = 1; i < this->_size; i++)
	{
		if (this->get(i-1) > this->get(i))
			return false;
	}
	return true;
}

void LinkedList::append(int value)
{
	Node *node = new Node(value);
	if (this->_size == 0)
	{
		this->_head = node;
		this->_tail = node;
		this->_mid = node;
	}
	else
	{
		node->_prev = this->_tail;
		this->_tail->_next = node;
		this->_tail = node;
	}

	// update size
	this->_size++;
	
	// update mid node
	if ( (this->_size > 1) && (this->_size % 2 == 1) )
		this->_mid = this->_mid->_next;
}

void LinkedList::append(int values[], size_t n)
{
	for (size_t i = 0; i < n; i++)
		this->append(values[i]);
}

void LinkedList::push(int value)
{
	// handle empty list
	if (this->_size == 0)
		return this->append(value);

	Node *node = new Node(value);
	this->_head->_prev = node;
	node->_next = this->_head;
	this->_head = node;

	// update size
	this->_size++;

	// update mid node
	if ((this->_size > 1) && (this->_size%2 == 0))
		this->_mid = this->_mid->_prev;
}

void LinkedList::push(int values[], size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		size_t idx = n-1-i;
		this->push(values[idx]);
	}
	return;
}

int LinkedList::pop()
{
	// handle empty list
	if (this->_size <= 0)
	{
		std::clog << "Warning! Popping from empty list! Returning -1." << std::endl;
		return -1;
	}

	// update list
	Node *tmp = this->_head;
	if (this->_size == 1)
		this->_head = this->_tail = this->_mid = nullptr;
	else
	{
		this->_head = tmp->_next;
		this->_head->_prev = nullptr;
	}

	// update size
	this->_size--;

	// update mid node
	if (this->_size > 1 && this->_size%2 == 1)
		this->_mid = this->_mid->_next;
	else if (this->_size == 1)
		this->_mid = tmp->_next;

	// free memory
	int data = tmp->_data;
	delete tmp;

	return data;
}

int LinkedList::popTail()
{
	// handle empty list
	if (this->_size <= 0)
	{
		std::clog << "Warning! Popping from empty list! Returning -1." << std::endl;
		return -1;
	}

	// update list
	Node *tmp = this->_tail;
	if (this->_size == 1)
		this->_tail = this->_head = this->_mid = nullptr;
	else
	{
		this->_tail = tmp->_prev;
		this->_tail->_next = nullptr;
	}

	// update size
	this->_size--;

	// update mid node
	if ( (this->_size > 1) && (this->_size%2 == 0))
		this->_mid = this->_mid->_prev;

	// free memory
	int data = tmp->_data;
	delete tmp;

	return data;
}

int LinkedList::pop(size_t index)
{
	// handle single element or empty list
	if (this->_size <= 1)
		return this->pop();

	// handle negative index
	if (index < 0)
	{
		std::clog << "Warning! Negative index, returning HEAD!" << std::endl;
		return this->pop();
	}

	// handle index out of bounds
	if (index >= this->_size)
	{
		std::clog << "WARNING! Index out of bounds, returning TAIL!" << std::endl;
		return this->popTail();
	}

	// update list
	Node *tmp= this->_head;
	for (size_t i = 0; i < index; i++)
		tmp = tmp->_next;
	tmp->_prev->_next = tmp->_next;
	tmp->_next->_prev = tmp->_prev;

	// update mid node
	if (this->_mid == tmp)
		this->_mid = tmp->_prev;
	else
		this->_mid = this->_mid->_prev;

	// update size
	this->_size--;

	// free memory and return
	int data = tmp->_data;
	delete tmp;
	return data;
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

