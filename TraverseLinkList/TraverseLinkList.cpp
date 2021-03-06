// TraverseLinkList.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct LinkList
{
	int data;
	LinkList* next;
};
// 思路：带头结点链表建立过程就要找准位置插入，然后输出
// 1.遍历链表，找到第一个大于插入值的结点，两个指针，其中一个保存前驱结点。
// 2.new个结点插入，反复1.2步
// 3.遍历
void insert(LinkList* head, int num)
{
	// 0.处理异常情况
	if (head == NULL)
		return;
	// 1.两个指针遍历
	LinkList* cur = head->next;
	LinkList* pre = head;
	bool isLast = true;  //最后一位特殊招待
	while (cur != NULL)
	{
		// 2.找到第一个大于插入值的位置
		if (num < cur->data)
		{
			// 3.新建结点，并插入
			LinkList* node = new LinkList;
			node->data = num;
			node->next = cur;
			pre->next = node;
			isLast = false;
			break;
		}
		// 4.没有找到，继续往后找
		pre = cur;
		cur = cur->next;
	}
	if (isLast)
	{
		// 最后一位则在pre后面直接插入节点
		LinkList* node = new LinkList;
		node->data = num;
		node->next = cur;
		pre->next = node;
	}
}

void printResult(LinkList* head)
{
	//0. 处理异常情况
	if (head == NULL)
	{
		return;
	}
	LinkList* cur = head->next;
	//1. 开始遍历
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

int main()
{
	int n;
	LinkList* head=new LinkList;
	head->next = NULL;
	while (scanf("%d", &n))
	{
		// 1.建立链表
		int num;
		for (int i = 0;i < n;i++)
		{
			scanf("%d", &num);
			insert(head, num);
		}
		// 2.遍历
		printResult(head);

		// 3.清空链表，即释放原先的结点
		head->next = NULL;
	}
    return 0;
}

