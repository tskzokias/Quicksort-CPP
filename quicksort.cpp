#include "quicksort.h"
#include <algorithm>


int partition(int* arr, unsigned low, unsigned high)
{
	int pivot = arr[high]; 
	unsigned int i = (low);   

	for (unsigned int j = low; j < high + 1; ++j)
	{
		
		if (arr[j] < pivot)
		{
			std::swap(arr[j], arr[i]);
			++i;     
		}
	}
	std::swap(arr[i], arr[high]);	
	return i ;
}

void quicksort_rec(int* arr, unsigned low, unsigned high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		if (pi == 0)
		{
			quicksort_rec(arr, low, pi);
			quicksort_rec(arr, pi, high);
		}
		else
		{
			quicksort_rec(arr, low, pi - 1);
			quicksort_rec(arr, pi + 1, high);
		}
	}
}

void quicksort(int* arr, unsigned low, unsigned high)
{
	if (low < high)
	{
		//int pivot = arr[high];

		//if (pivot <= 0)
		//	break;
		
	//	int pi = partition(arr, low, high);

		quicksort_rec(arr, low, high-1);
 
		//quicksort(arr, low, pi - 1);
		//quicksort(arr, pi + 1, high);
	}
}


