// SpecialSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void Swap(int* a, int* b)
{
	int c;
	c = *b;
	*b = *a;
	*a = c;
}

// 堆排序
void adjustHeap(int *data, int node, int length)  //调整堆 
{
	int lchild = 2 * node + 1;       //i的左孩子节点序号 
	int rchild = 2 * node + 2;     //i的右孩子节点序号 
	int parent = node;
	while (lchild <= length-1)  //左孩子在堆里
	{
		if (rchild <= length-1)  //若右孩子也在堆里
		{
			if (data[rchild] > data[lchild])  //左孩子比右孩子小
			{
				// 右孩子与父亲节点比较
				if (data[parent] < data[rchild])
				{
					Swap(&data[parent], &data[rchild]);
					parent = rchild;
					lchild = parent * 2 + 1;
					rchild = parent * 2 + 2;
					continue;
				}
				else
					break;
			}
		}
		if (data[lchild] > data[parent]) //左孩子大于父亲节点
		{
			Swap(&data[lchild], &data[parent]);
			parent = lchild;
			lchild = parent * 2 + 1;
			rchild = parent * 2 + 2;
		}
		else
			break;
	}
}

void buildHeap(int *data, int length)    //建堆 
{
	for (int i = length / 2 - 1;i >= 0;i--)    //非叶节点最大序号值为length/2 - 1 
	{
		adjustHeap(data, i, length);
	}
}

void HeapSort(int *data, int length)    //堆排序 
{
	// 0.异常情况
	if (data == NULL || length <= 0)
		return;
	int i;
	// 建堆
	buildHeap(data, length);
	// 调整堆顶元素，并进行堆调整
	for (i = length-1;i >= 1;i--)
	{
		Swap(&data[0], &data[i]);    //交换堆顶和最后一个元素，即每次将剩余元素中的最大者放到最后面 
		adjustHeap(data, 0, i);      //重新调整堆顶节点成为大顶堆
	}
}

int data[1000];

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
		HeapSort(data, n);  //堆排序
		printf("%d\n", data[n - 1]);
		for (int i = 0;i < n-1;i++)
		{
			if (i == n - 2)
			{ 
				printf("%d\n", data[i]);
				break;
			}
			printf("%d ", data[i]);

		}
	}
    return 0;
}

