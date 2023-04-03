//
// Created by Gowi on 2023/2/20.
//

//括号匹配

#include <cstdio>
#include "../myStack.h"

int main()
{
	int i = 0;
	char ch;
	Stack<char> s = Stack<char>(100);
	FILE *f = fopen("../2019/data.txt", "r+");
	if (f == NULL)
	{
		printf("文件操作失败\n");
	}
	while ((ch = fgetc(f)) != EOF)
	{
		if (ch == '(')
		{
			s.push(ch);
		}
		if (s.getTop() == '(' && ch == ')')
		{
			i++;
			s.pop();
		}
	}
	printf("%d\n", i);
	return 0;
}
