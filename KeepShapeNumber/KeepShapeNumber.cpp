// KeepShapeNumber.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdlib>
#include <cstdio>
using namespace std;
// 思路：守形数
// 1.计算数字的位数，记为k
// 2.平方数字，得到低k位
// 3.比较，打印结果

int getK(int num)
{
	int k = 0;
	do {
		k++;
		num /= 10;
	} while (num);
	return k;
}

int getKOfPower(int num,int k)
{
	int power = num * num;
	int result=0;
	for (int i = 0;i < k;i++)
	{
		result = result + pow(10, i)*(power % 10);
		power /= 10;
	}
	return result;
}

int main()
{
	int n;
	while (scanf("%d", &n))
	{
		int k = getK(n);
		int result = getKOfPower(n, k);
		if (n == result)
		{
			printf("Yes!\n");
		}
		else
		{
			printf("No!\n");

		}
	}
    return 0;
}

