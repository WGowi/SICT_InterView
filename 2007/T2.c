//
// Created by 伍高巍 on 2023/2/18.
//

//编程将一个实数分解为它的整数和小数部分。

#include <stdio.h>

int main()
{
	float a, c;
	int b;
	scanf("%f", &a);
	b = a;//隐性类型转换
	c = a - b;
	printf("整数部分:%d\n", b);
	printf("小数部分:%f\n", c);
	return 0;
}