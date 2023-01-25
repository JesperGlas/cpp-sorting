#include "sorting.hpp"

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
	
	// define original array
	int arr1[] = {1, 2, 4, 1, 5, 3, 6, 8, 4, 3};
	size_t size = sizeof(arr1) / sizeof(arr1[0]);
	std::cout << "Original array: ";
	printArray(arr1, size);
	
	// insertion sort array
	int arr2[size];
	Sorting::insertion_copy(arr1, size, arr2);
	std::cout << "Sorted array: ";
	printArray(arr2, size);

	// make sure original is unmodified
	std::clog << "Original array: ";
	printArray(arr1, size);
}

