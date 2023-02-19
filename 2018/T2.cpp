//
// Created by 伍高巍 on 2023/2/19.
//

//把一个文件中的字符排序后放入到另外一个文件中

#include <cstdio>
#include <cstdlib>

#define N 100

int main()
{
	int n = 0;
	char str[N], ch;
	FILE *f1 = fopen("../2018/data.txt", "r+");
	FILE *f2 = fopen("../2018/new_data.txt", "w");
	if (f1 == NULL || f2 == NULL)
	{
		printf("文件操作失败\n");
		exit(0);
	}
	while ((ch = fgetc(f1)) != EOF)
	{
		if (ch != ',')
		{
			str[n++] = ch;
		}
	}
	str[n] = '\0';
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			if (str[j] > str[j + 1])
			{
				char c = str[j];
				str[j] = str[j + 1];
				str[j + 1] = c;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		fprintf(f2, "%c,", str[i]);
	}
	return 0;
}