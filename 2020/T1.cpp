//
// Created by Gowi on 2023/2/20.
//

//编写一个函数实现十进制向二进制转换的功能,函数的输入为一个十进制数,输出为一个二进制数,如输入37,输出为100101

#include "../myStack.h"

void fun(int x)
{
	if (x)
	{
		fun(x / 2);
		printf("%d", x % 2);
	}
}

int main()
{
	int x;
	scanf("%d", &x);
	if (x == 0)
	{
		printf("0");
	}
	else
	{
		fun(x);
	}
	printf("\n");
	Stack<int> s = Stack<int>(x);
	do
	{
		s.push(x % 2);
		x /= 2;
	}
	while (x);
	while (!s.IsEmpty())
	{
		printf("%d", s.pop());
	}
	return 0;
}
