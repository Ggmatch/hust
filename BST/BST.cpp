// BST.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include "stdio.h"

struct  BST
{
	BST* leftChild;
	BST* rightChild;
	BST* parent;
	int data;
};

// BST插入操作:root为BST的根节点，data要插入的数值，node为新插入的节点并返回
bool insert(BST* root, int data, BST** node)
 {
	// 0.处理异常情况
	if (root == NULL)
	{
		return false;
	}

	// 1.循环找到插入位置
	BST* tmp = root;
	BST* parent = root;
	bool isRight = true;
	while (tmp)
	{
		parent = tmp;  //记录下父节点

		// 比较data大小决定往哪走
		if (data > tmp->data)  //往右走
		{
			tmp = tmp->rightChild;
			isRight = true;
		}
		else  //不然，向左走
		{
			tmp = tmp->leftChild;
			isRight = false;
		}

	}

	// 跳出来，说明到插入位置了，开始插入节点
	BST* insertNode = new BST;
	insertNode->data = data;
	insertNode->rightChild = insertNode->leftChild = NULL;
	insertNode->parent = parent;
	if (isRight)  //插入右边
		parent->rightChild = insertNode;
	else  //插入左边
		parent->leftChild = insertNode;
	*node = insertNode;  // 返回该节点

	return true;
}

int main()
{
	//测试
	//正常情况
	//边界情况：一个节点
	//异常情况:null指针
	int NodeNumbers;
	BST* root=NULL;
	int data;
	while (scanf("%d", &NodeNumbers))
	{
		// 输入数字
		for (int i = 0;i < NodeNumbers;++i)
		{
			scanf("%d", &data);

			// 处理第一个节点
			if (i == 0)
			{
				root = new BST;
				root->data = data;
				root->leftChild = root->rightChild = root->parent= NULL;
				printf("%d\n", -1);
			}
			else
			{
				BST* node=NULL;
				if (insert(root, data, &node))
				{
					//插入成功后，打印父亲节点的数值
					printf("%d\n", node->parent->data);
				}
			}
		}

		// 存在内存泄漏，没有delete掉那些new 出来的内存，考试中为了速度不用考虑
	}

	
    return 0;
}

