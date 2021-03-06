// Upstairs.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*
	问题描述：
	N阶楼梯上楼问题：一次可以走两阶或一阶，问有多少种上楼方式。
	（要求采用非递归）
*/

// 思路：f(N)表示N阶楼梯的上楼方式
// f(N)=f(N-1)+f(N-2),f(1)=1,f(2)=2

long long getWays(int N)
{
	//处理异常情况
	if (N < 1 || N >= 90)
		return -1;
	long long f1 = 1, f2 = 2,fn;
	if (N == 1)
		return f1;
	if (N == 2)
		return f2;

	for (int i = 3;i <= N;i++)
	{
		fn = f1 + f2;
		f1 = f2;
		f2 = fn;
	}
	return fn;
}

int main()
{
	int N;
	while (scanf("%d", &N))
	{
		long long ways = getWays(N);
		printf("%lld\n", ways);
	}
    return 0;
}

