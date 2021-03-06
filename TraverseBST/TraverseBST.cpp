// TraverseBST.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*
	问题描述：
	输入一系列整数，建立二叉排序数，并进行前序，中序，后序遍历。
*/

struct BST 
{
	int data;
	BST* leftChild;
	BST* rightChild;
};

// 插入操作
void insertBST(BST* root, int data)
{
	// 0.处理异常情况
	if (root == NULL)
		return;
	BST* cur = root;
	while (cur)
	{
		// 1.data>当前结点的值 且 右不为空 ，转向右边
		if (data > cur->data&&cur->rightChild != NULL)
		{
			cur = cur->rightChild;
		}
		else if(data>cur->data&&cur->rightChild==NULL)  //2.data>当前结点的值 且 右为空，插入右边
		{
			BST* node = new BST;
			node->data = data;
			node->leftChild = node->rightChild = NULL;
			cur->rightChild = node;
			break;
		}
		else if (data < cur->data&&cur->leftChild != NULL)  //3.转向左边
		{
			cur = cur->leftChild;
		}
		else if (data < cur->data&&cur->leftChild == NULL)  //4.插入左边
		{
			BST* node = new BST;
			node->data = data;
			node->leftChild = node->rightChild = NULL;
			cur->leftChild = node;
			break;
		}
	}
}
// 打印操作
void print(BST* node)
{
	// 处理异常情况
	if (node == NULL)
		return;
	printf("%d ", node->data);
}

// 前序遍历
void PreOrder(BST* root)
{
	//
	if (root)
	{
		//打印当前结点
		print(root);
		//左孩子
		PreOrder(root->leftChild);
		//右孩子
		PreOrder(root->rightChild);

	}
}
// 中序遍历
void InOrder(BST* root)
{
	//
	if (root)
	{
		//左孩子
		InOrder(root->leftChild);
		//打印当前结点
		print(root);
		//右孩子
		InOrder(root->rightChild);
	}
}

// 后序遍历
void PostOrder(BST* root)
{
	//
	if (root)
	{
		//左孩子
		PostOrder(root->leftChild);
		//右孩子
		PostOrder(root->rightChild);
		//打印当前结点
		print(root);
	}
}

void deleteNode(BST* root)
{
	if (root)
	{
		//左孩子
		deleteNode(root->leftChild);
		//右孩子
		deleteNode(root->rightChild);
		//释放当前结点
		delete root;
	}
}

int main()
{
	BST* root;
	int n;
	while (scanf("%d", &n))
	{
		// 第一个单独考虑
		int data;
		scanf("%d", &data);
		root = new BST;
		root->data = data;
		root->rightChild = root->leftChild = NULL;
		for (int i = 1;i < n;i++)
		{
			//插入操作
			scanf("%d", &data);
			insertBST(root, data);
		}
		//打印遍历结果
		//前序
		PreOrder(root);
		printf("\n");
		//中序
		InOrder(root);
		printf("\n");
		//后序
		PostOrder(root);
		printf("\n");

		//释放BST结点
		deleteNode(root);
	}
    return 0;
}

