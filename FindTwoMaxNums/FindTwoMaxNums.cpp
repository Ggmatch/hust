// FindTwoMaxNums.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
using namespace std;

// 思路：
// 1. 遍历，找到第一大的元素，记录下标
// 2. 遍历，找到第二大的元素，记录下标
// 3. 下标小的，填在第一行，大的填第二行
// 4. 输出result

int Data[4][5];
int Result[2][5];

void find(int data[][5])
{
	for (int k = 0;k < 5;k++)
	{
		// 1.找max的下标
		int indexOfMax=0;
		for (int i = 0;i < 4;i++)
		{
			if (data[i][k] > data[indexOfMax][k])  //大于，则取大的下标
			{
				indexOfMax = i;
			}
		}

		// 2.找secondMax的下标
		int indexOfSecMax;
		if (indexOfMax != 0)
			indexOfSecMax = 0;
		else
			indexOfSecMax = 1;
		for (int i = 0;i < 4;i++)
		{
			if (i == indexOfMax)
				continue;
			if (data[i][k] > data[indexOfSecMax][k])  //大于，则取大的下标
			{
				indexOfSecMax = i;
			}
		}

		// 3.填入result中
		if (indexOfMax < indexOfSecMax)  //小的填第一行
		{
			Result[0][k] = data[indexOfMax][k];
			Result[1][k] = data[indexOfSecMax][k];
		}
		else
		{
			Result[0][k] = data[indexOfSecMax][k];
			Result[1][k] = data[indexOfMax][k];
		}
	}
}

void printResult(int result[][5])
{
	// 4.输出结果
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			if (j == 4)
			{
				printf("%d\n", result[i][j]);
				break;
			}
			printf("%d ", result[i][j]);

		}
	}
}

int main()
{
	// 清空数据
	while (true)
	{
		for (int i = 0;i < 4;i++)
		{
			for (int j = 0;j < 5;j++)
			{
				scanf("%d", &Data[i][j]);
			}
		}
		find(Data);
		printResult(Result);
	}
    return 0;
}

