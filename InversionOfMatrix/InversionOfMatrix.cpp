// InversionOfMatrix.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MaxSize 50

bool inverse(int matrix[][MaxSize], int dimension)
{
	// 0.异常情况处理
	if (matrix == NULL || dimension <= 0)
		return false;
	// 1.核心部分
	for(int i=1;i<dimension;++i)
		for (int j = 0;j < i;++j)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
	return true;
}

int matrix[MaxSize][MaxSize];

int main()
{
	// 测试
	// 正常情况

	// 异常情况

	// 边界情况：1*1
	int dimension;
	while (scanf("%d", &dimension))
	{
		for (int i = 0;i < dimension;++i)
			for (int j = 0;j < dimension;++j)
				scanf("%d", &matrix[i][j]);

		// 转置
		if (inverse(matrix, dimension))
		{
			// 打印结果
			for (int i = 0;i<dimension;++i)
				for (int j = 0;j < dimension;++j)
				{
					if (j == dimension - 1)
						printf("%d\n", matrix[i][j]);
					else
						printf("%d ", matrix[i][j]);

				}
		}
		
	}
    return 0;
}

