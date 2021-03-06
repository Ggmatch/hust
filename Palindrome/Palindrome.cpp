// Palindrome.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstring>
using namespace std;

/*
	问题描述：给出一个长度不超过1000的字符串，判断它是不是回文(顺读，逆读均相同)的。
	思想：直接一个循环即可
*/

char data[1005];
int main()
{
	while (scanf("%s", data))
	{
		int len = strlen(data);
		int i;
		bool isPalindrome = true;
		for (i = 0;i < len/2;i++)
		{
			if (data[i] != data[len - 1 - i])
			{
				printf("No!\n");
				isPalindrome = false;
				break;
			}
		}
		if (isPalindrome)
		{
			printf("Yes!\n");
		}
	}
    return 0;
}

