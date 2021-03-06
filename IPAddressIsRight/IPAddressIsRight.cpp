// IPAddressIsRight.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MaxSize 50
char result[MaxSize][MaxSize];
char str[MaxSize];
// 一个简单的splitString函数，依据char分割由char紧密连接的string。
// 如：255.255.255.255中的'.' 或者 hello world you 中的空格。
bool splitString(char str[], int length, char Reg, char result[][MaxSize])
{
	// 0.异常情况处理
	if (str == NULL || result == NULL||length<=0)
		return false;
	// 1.核心部分
	char* source = str;
	int count = 0,num=0;  // count计数，num表示在result中存放字符串的顺序
	for (int i = 0;i < length;++i)
	{
		// 根据当前是不是分隔符来划分字符串
		if (str[i] == Reg||i==length-1)
		{
			// 把前面的字符串复制到result中
			memcpy(result[num], source, count);
			result[num][count+1] = '\0';
			// count重新计数,num\source移位
			source += count+1;
			count = 0;
			num++;
		}
		else
		{
			// count计数
			count++;
		}
	}
	return true;
}

bool IsRight(char str[], int length)
{
	// 0.异常情况处理
	if (str == NULL || length <= 0)
		return false;
	// 将字符串转换成数值，进行比较 
	int data = atoi(str);
	if (data >= 0 && data <= 255)
		return true;
	else
		return false;
}

int main()
{
	// 测试
	// 正常情况 256.2.1.1
	// 边界情况 
	// 异常情况
	while (fgets(str, MaxSize, stdin))
	{
		int length = strlen(str);
		bool isRight = true;
		if (splitString(str, length, '.', result))
		{
			for (int i = 0;i < 4;i++)
			{
				length = strlen(result[i]);
				if (!IsRight(result[i], length))
				{
					isRight = false;
					break;
				}
			}
		}
		if(isRight)
			printf("%s\n", "Yes!");
		else
			printf("%s\n", "No!");
	}
    return 0;
}

