//
// Created by Gowi on 2023/2/19.
//

//编写程序，将字符串中第n个字符开始的全部字符复制成另一个字符串。要求在主函数中输入字符串及n的值并输出复制的结果，在被调用函数中完成复制。

#include <cstdio>

#define N 100

void strCpy(char *str1, char *str2, int n)
{
	int i = n, j = 0;
	for (; str1[i] != '\0'; i++, j++)
	{
		str2[j] = str1[i];
	}
	str2[j] = '\0';
}

int main()
{
	char str1[N], str2[N];
	int n;
	scanf("%d", &n);
	scanf("%s", str1);
	strCpy(str1, str2, n);
	printf("%s\n", str2);
}