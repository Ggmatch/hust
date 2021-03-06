// SysMatrix.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// 思路：判断对称
// 1.循环上三角，然后与下三角对应位置的数值比较
// 2.有一个不符合，即不是对称矩阵
int matrix[100][100];

bool isSysMatrix(int matrix[][100], int dimension)
{
	// 1.循环上三角
	for (int i = 0;i < dimension-1;i++)
	{
		for (int j = i + 1;j < dimension;j++)
		{
			// 2.与对应位置比较
			if (matrix[i][j] != matrix[j][i])
				return false;
		}
	}
	return true;
}

int main()
{
	int dimension;
	while (scanf("%d", &dimension))
	{
		// 1.输入数据
		for (int i = 0;i < dimension;i++)
			for (int j = 0;j < dimension;j++)
				scanf("%d", &matrix[i][j]);
		// 2.判断对称
		if (isSysMatrix(matrix, dimension))
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

