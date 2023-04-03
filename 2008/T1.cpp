//
// Created by Gowi on 2023/2/24.
//

//                3
//              4   5
//           8  3  4  9
//        4  4  2  8   3
//      1   5   8  8  7  4
//   8  7  6  2  14  8  9  4

#include <cstdio>

#define N 10

int main()
{
	int triangle[N][N], cost[N][N], n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			scanf("%d", &triangle[i][j]);
		}
	}
	cost[0][0] = triangle[0][0];
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j == 0)
			{
				cost[i][j] = triangle[i][j] + cost[i - 1][j];
			}
			else
			{
				int max_cost_last;
				if (cost[i - 1][j] < cost[i - 1][j - 1])
				{
					max_cost_last = cost[i - 1][j - 1];
				}
				else
				{
					max_cost_last = cost[i - 1][j];
				}
				cost[i][j] = triangle[i][j] + max_cost_last;
			}
		}
	}
	int max_cost = cost[n - 1][0], max_i = n - 1, max_j = 0;
	for (int i = 1; i < n; ++i)
	{
		if (max_cost < cost[n - 1][i])
		{
			max_cost = cost[n - 1][i];
			max_j = i;
		}
	}
	printf("max cost:%d\n", max_cost);
	return 0;
}