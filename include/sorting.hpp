#pragma once

#include <iostream>

class Sorting
{
private:
	static void swap(int &a, int &b);
public:
	static void insertion(int src[], size_t n);
	static void insertion_copy(int src[], size_t n, int dst[]);
};
