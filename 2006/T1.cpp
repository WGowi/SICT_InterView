//
// Created by Gowi on 2023/2/17.
//

//1、 编写一个程序，对输入的一行字符，分别统计出其中英文字母、空格、数字和其它字符各自的数目。

#include <cstdio>

int main()
{
	int Char_C = 0, Num_C = 0, Black_C = 0, Other_c = 0, i = 0;
	char str[100];
	while (scanf("%c", &str[i]) != EOF)
	{
		if ((str[i] <= 'Z' && str[i] >= 'A') || (str[i] <= 'z' && str[i] >= 'a'))
		{
			Char_C++;
		}
		else if (str[i] <= '9' && str[i] >= '0')
		{
			Num_C++;
		}
		else if (str[i] == ' ')
		{
			Black_C++;
		}
		else
		{
			Other_c++;
		}
		i++;
	}
	printf("字母数目:%d\n", Char_C);
	printf("数字数目:%d\n", Num_C);
	printf("空格数目:%d\n", Black_C);
	printf("其他字符数目:%d\n", Other_c);
	return 0;
}