// sort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
#include "time.h"
// 快速排序
// 一次分配过程
void Swap(int* a, int *b)
{
	int c;
	c = *b;
	*b = *a;
	*a = c;
}

int Partition(int* data, int start, int end)
{
	// 0.处理异常情况
	/*if (data == NULL || start > end)
		return ;*/
	// 1.核心部分
	//srand(time(NULL));  //种子
	//int index = rand() % (end - start) + start;
	//Swap(&data[index], &data[start]);
	int i = start, j = end, tmp = data[start];
	while (i < j)
	{
		while (i < j&&tmp < data[j]) j--;
		if (i < j)
		{
			data[i]=data[j];
			i++;
		}
		while (i<j&&tmp>data[i]) i++;
		if (i < j)
		{
			data[j] = data[i];
			j--;
		}
	}
	data[i] = tmp;
	return i;
}

void qsort(int* data, int start, int end)
{
	// 0.处理异常情况
	if (data == NULL || start > end)
		return;
	// 1.核心部分
	int index = Partition(data, start, end);
	if (index > start)
		qsort(data, start, index-1);
	if (index < end)
		qsort(data, index+1, end);
}

// 归并排序
int data[100];
int main()
{
	// 测试
	// 正常情况
	// 边界情况
	// 异常情况
	int n;
	while (scanf("%d", &n))
	{
		for (int i = 0;i < n;i++)
			scanf("%d", &data[i]);
		qsort(data, 0, n - 1);
		for (int i = 0;i < n;i++)
		{
			if (i == n - 1)
				printf("%d\n", data[i]);
			else
				printf("%d ", data[i]);

		}
	}
    return 0;
}

