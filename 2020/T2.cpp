//
// Created by Gowi on 2023/2/20.
//

//请编写一个排序算法,实现对数字x[n]的排序,要求时间复杂度不高于O(nlogn)。

#define N 10

#include <cstdio>

int partition(int x[], int low, int high)
{
	int pivot = x[low];
	while (low < high)
	{
		while (low < high && pivot <= x[high])
		{
			high--;
		}
		x[low] = x[high];
		while (low < high && pivot >= x[low])
		{
			low++;
		}
		x[high] = x[low];
	}
	x[low] = pivot;
	return low;
}

void QuickSort(int x[], int low, int high)
{
	if (low < high)
	{
		int pivot_pos = partition(x, low, high);
		QuickSort(x, low, pivot_pos - 1);
		QuickSort(x, pivot_pos + 1, high);
	}
}

int main()
{
	int x[N] = {22, 5, -4, -139, 5, 124, 46, 234, 64, 2}, low = 0, high = N - 1;
	QuickSort(x, low, high);
	for (int i = 0; i < N; ++i)
	{
		printf("%d,", x[i]);
	}
	return 0;
}
