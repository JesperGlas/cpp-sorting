#include "sorting.hpp"
#include <algorithm>

/* ### PRIVATE ### */

void Sorting::swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

/* ### PUBLIC ### */

void Sorting::insertion(int src[], size_t n)
{
	size_t count = 0;
	size_t i = 0;
	while (i < n-1)
	{
		count++;
		if (src[i+1] < src[i])
		{
			swap(src[i+1], src[i]);
			if (i > 0)
				i--;
		}
		else
			i++;
	}
	std::clog << "[insertion] Count: " << count << std::endl;
}

void Sorting::insertion_copy(int src[], size_t n, int dst[])
{
	std::copy(src, src+n, dst);
	Sorting::insertion(dst, n);
	return dst;
}
