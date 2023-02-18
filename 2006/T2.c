//
// Created by 伍高巍 on 2023/2/17.
//

//有n个整数，使前面各数顺序向后移m个位置，最后m个数变成最前面的m个数，如下图所示

#include <stdio.h>

int main(void)
{
	int A[100] = {0}, n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &A[(i + m < n) ? i + m : (i + m) % n]);
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ",A[i]);
	}
	return 0;
}
