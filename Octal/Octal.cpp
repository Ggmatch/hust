// Octal.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*
	问题描述：输入一个整数，将其转换成八进制数输出。
*/

#include <stdio.h>
#include <stdlib.h>

// 思路：除8取余法，不过输出是按从下往上，所以需要用到栈，这里递归即可实现输出的效果

void change(int n)
{
	if (n == 0)
		return;
	else
	{
		change(n / 8);
		printf("%d", n % 8);
	}
}

int main()
{
	int N;
	while (scanf("%d", &N) != EOF)
	{
		change(N);
		printf("\n");
	}
}
