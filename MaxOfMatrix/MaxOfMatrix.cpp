// MaxOfMatrix.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// 思路：
// 1.循环比较，找到最大值的下标，记录下来为k
// 2.遍历，累加，记为sum
// 3.把sum填入[k]中
int data[100][100];
int main()
{
	int m, n;
	while (scanf("%d%d", &m, &n))
	{
		
		for (int i = 0;i < m;i++)
		{
			int sum = 0, k;
			// 1.读数据
			for (int j = 0;j < n;j++)
				scanf("%d", &data[i][j]);
			// 2.找K
			k = 0;
			for (int j = 1;j < n;j++)
			{
				if (data[i][j] > data[i][k]) //则换为j
					k = j;
			}
			// 3.求sum
			for (int j = 0;j < n;j++)
				sum += data[i][j];
			// 4.用sum替换[k]
			data[i][k] = sum;
		}

		// 5.输出结果
		for (int i = 0;i < m;i++)
		{
			for (int j = 0;j < n;j++)
			{
				if (j == n - 1)
				{
					printf("%d\n", data[i][j]);
					break;
				}
				printf("%d ", data[i][j]);
			}
		}
	}
    return 0;
}

