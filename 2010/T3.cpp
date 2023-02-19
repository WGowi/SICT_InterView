//
// Created by 伍高巍 on 2023/2/19.
//

//完成一个函数：
//char *BeforeData(char *today)
//说明：today是输入的日期，格式为“YYYY-MM-DD”，返回也为“YYYY-MM-DD”，
//返回值为输入值的前一天，如：today = “2017-03-19”，返回：“2017-03-18”

#include <cstdio>
#include <cstring>

char *BeforeData(char *today)
{
	char bd[11];
	int year = 0, month = 0, day = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (i < 4)
		{
			year = year * 10 + today[i] - '0';
		}
		else if (i < 7 && i > 4)
		{
			month = month * 10 + today[i] - '0';
		}
		else if (i > 7)
		{
			day = day * 10 + today[i] - '0';
		}
	}
	if (day == 1)
	{
		if (month == 1)
		{
			month = 12;
			year--;
		}
		else if (month - 1 == 1 || month - 1 == 3 || month - 1 == 5 || month - 1 == 7 || month - 1 == 9 ||
				 month - 1 == 10 || month - 1 == 12)
		{
			month--;
			day = 31;
		}
		else if (month - 1 == 2)
		{
			if (year % 4 == 0 || year % 400 == 0)
			{
				month--;
				day = 29;
			}
			else
			{
				month--;
				day = 28;
			}
		}
		else
		{
			month--;
			day = 30;
		}
	}
	else
	{
		day = day - 1;
	}
	int k = 1000;
	for (int i = 0; i < 10; ++i)
	{
		if (i < 4)
		{
			bd[i] = year / k + '0';
			year = year % k;
			k /= 10;
		}
		else if (i == 4)
		{
			bd[i] = '-';
			k = 10;
		}
		else if (i < 7)
		{
			bd[i] = month / k + '0';
			month = month % k;
			k /= 10;
		}
		else if (i == 7)
		{
			bd[i] = '-';
			k = 10;
		}
		else
		{
			bd[i] = day / k + '0';
			day = day % k;
			k /= 10;
		}
	}
	bd[10] = '\0';
	printf("%s\n", bd);
	return bd;
}

int main()
{
	BeforeData("2023-02-19");
}