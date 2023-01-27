#include <iostream>
#include <random>

#include "LinkedList.hpp"

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
	
	LinkedList lst = LinkedList();
	size_t size = static_cast<int>(getRandom(1, 20));
	for (size_t i = 0; i < size; i++)
		lst.append(getRandom(1, 99));
	std::cout << "List: (" << lst.getSize() << "): " << lst << std::endl;
	
	// get at index
	std::cout << "At index 0: " << (*lst.getNode(0)) << std::endl;
	std::cout << "At index 3: " << (*lst.getNode(3)) << std::endl;

	// sort
	lst.sort_ins();
	std::cout << "Sorted: " << lst << std::endl;

	// push
	lst.push(100);
	std::cout << "Pushed 100: " << lst << std::endl;

	// pop
	std::cout << "Pop first elem (" << lst.pop() << "): " << lst << std::endl;

	// empty list by popping
}

