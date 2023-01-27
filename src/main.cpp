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
}

