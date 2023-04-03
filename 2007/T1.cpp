//
// Created by Gowi on 2023/2/17.
//

//输入数组，最大的与第一个元素交换，最小的与最后一个元素交换，输出数组

#include <stdio.h>

#define N 100

int main()
{
	int A[N] = {0}, n, max_index = 0, min_index = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &A[i]);
		if (A[i] < A[min_index])
		{
			min_index = i;
		}
		if (A[i] > A[max_index])
		{
			max_index = i;
		}
	}
	int temp;
	if (min_index == 0 && max_index == n - 1)//若最大的数为数组最后一个数字且最小的数字为数组第一个数字则只需要交换两者位置，否则和相应位置的数字交换
	{
		temp = A[max_index];
		A[max_index] = A[min_index];
		A[min_index] = temp;
	}
	else
	{
		temp = A[0];
		A[0] = A[max_index];
		A[max_index] = temp;
		temp = A[n - 1];
		A[n - 1] = A[min_index];
		A[min_index] = temp;
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d,", A[i]);
	}
	return 0;
}