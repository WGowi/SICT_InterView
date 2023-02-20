//
// Created by 伍高巍 on 2023/2/20.
//

//输入一个年月日，再输入一个数字X（x为任意整数），输出加上X后的年月日（考虑跨年跨月 ，闰年闰月问题）

#include <cstdio>

int main()
{
	int year, month, day, x;
	scanf("%d,%d,%d,%d", &year, &month, &day, &x);
	day += x;
	while (1)
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day > 31)
			{
				day -= 31;
				month++;
			}
			else
			{
				break;
			}
			if (month > 12)
			{
				year++;
				month = 1;
			}
		}
		if (month == 2)
		{
			if (year % 4 == 0 || year % 400 == 0)
			{
				if (day > 29)
				{
					day -= 29;
					month++;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (day > 28)
				{
					day -= 28;
					month++;
				}
				else
				{
					break;
				}
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day > 30)
			{
				day -= 30;
				month++;
			}
			else
			{
				break;
			}
		}
	}
	printf("%d-%d-%d", year, month, day);
}