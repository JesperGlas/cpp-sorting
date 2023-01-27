#include <iostream>
#include <random>
#include <chrono>

#include "LinkedList.hpp"

std::chrono::steady_clock::time_point getTimeStamp()
{
	return std::chrono::steady_clock::now();
}

void printElapsedTime(std::chrono::steady_clock::time_point start)
{
	auto end = getTimeStamp();
	std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << " µs" << std::endl;
	std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << " ns" << std::endl;
}

int getRandom(int min, int max)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> distMinMax(min, max);
	return distMinMax(rng);
}

void printArray(int arr[], size_t n)
{
	std::cout << "[ ";
	for (size_t i = 1; i < n; i++)
	{
		std::cout << arr[i];
		if (i < n-1)
			std::cout << ", ";	
	}
	std::cout << " ]" << std::endl;
}

int main()
{
	std::cout << "Sorting demo!" << std::endl;

	std::clog << "Generating list.." << std::endl;
	LinkedList lst = LinkedList();
	size_t n = 10000;
	for (size_t i = 0; i < n; i++)
		lst.append(getRandom(0, n));

	std::clog << "Generated a list of " << n << " random elements.." << std::endl;

	// check that list is not sorted
	if (lst.isSorted())
		std::clog << "List is sorted.." << std::endl;
	else
		std::clog << "List is not sorted.." << std::endl;

	// sort list and time it
	auto start = getTimeStamp();
	lst.sort_ins();
	printElapsedTime(start);

	// check that list is sorted
	if (lst.isSorted())
		std::clog << "List is sorted.." << std::endl;
	else
		std::clog << "List is not sorted.." << std::endl;
}

