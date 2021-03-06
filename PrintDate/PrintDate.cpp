// PrintDate.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// 思路：打印日期，最主要的是判断闰年与否
// 1.输入年，第多少天
// 2.判断是否为闰年，若是，二月写29天，否则28天，有一个12个元素的数组记录每月份总天数
// 3.从1月累加，找到第一个大于它的月份，即在上一个月份中，再求具体多少日

bool isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) //是闰年
		return true;
	else
		return false;
}

int months[] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
int main()
{
	int year, days;
	while (scanf("%d", &year) && scanf("%d", &days))
	{
		// 1.判断闰年
		if (isLeapYear(year))
		{
			months[2] = 29;
		}
		else
		{
			months[2] = 28;
		}
		// 2.循环累加
		int month, day;
		int i,tmp=0;
		for (i = 1;i <= 12;i++)
		{
			tmp += months[i];
			// 3.若是超过days，跳出循环，当前i即为所求月份
			if (tmp >= days)
			{
				break;
			}
		}
		month = i;
		day = days - (tmp - months[i]);
		// 3.打印日期
		printf("%d-%02d-%02d\n", year, month, day);
	}
    return 0;
}

