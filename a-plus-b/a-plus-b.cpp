// a-plus-b.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
#include "string.h"

char num1[1001];
char num2[1001];
char result[1003];

bool plusNumbersNotEqualedLength(char* longer, int longLength, char* shorter, int shortLength, char* result);
bool plusNumbersEqualedLength(char* num1, char* num2, int length, char* result);

bool plus(char* num1, int length1, char* num2, int length2, char* result)
{
	// 0.处理异常情况
	if (num1 == NULL || length1 <= 0 || num2 == NULL || length2 < 0 || result == NULL)
		return false;
	// 1.核心部分
	// 总共只有三种情况：length1>length2;length1<length2;length1==length2
	// 前两种可以使用一种函数解决，后面一种单独一种函数
	bool b = false;
	if (length1 != length2)
	{
		if (length1 > length2)
			b=plusNumbersNotEqualedLength(num1, length1, num2, length2, result);
		else
			b=plusNumbersNotEqualedLength(num2, length2, num1, length1, result);

	}
	else
		b=plusNumbersEqualedLength(num1, num2, length1, result);
	if (b)
		return true;
	else
		return false;
}


bool plusNumbersNotEqualedLength(char* longer, int longLength, char* shorter, int shortLength, char* result)
{
	// 0.处理异常情况
	if (num1 == NULL || longLength <= 0 || num2 == NULL || shortLength < 0 || result == NULL)
		return false;
	// 1.核心部分
	bool IsInc = false;
	// 前半截相加
	for (int i = 0;i < shortLength;i++)
	{
		int tmp1 = longer[longLength - 1 - i] - '0';
		int tmp2 = shorter[shortLength - 1 - i] - '0';
		int res;
		if (IsInc)
			res = tmp1 + tmp2 + 1;
		else 
			res = tmp1 + tmp2;
		if (res >= 10)
		{
			IsInc = true;
			res -= 10;
		}
		else
		{
			IsInc = false;
		}
		result[longLength - i] = res + '0';
	}
	// 后半截相加
	for (int i = shortLength;i < longLength;i++)
	{
		int tmp1 = longer[longLength - 1 - i] - '0';
		int res;
		if (IsInc)
			res = tmp1+1;
		else
			res = tmp1;
		if (res >= 10)
		{
			IsInc = true;
			res -= 10;
		}
		else
		{
			IsInc = false;
		}
		result[longLength - i] = res + '0';
	}
	if (IsInc)
		result[0] = '1';
		
	return true;
}

bool plusNumbersEqualedLength(char* num1, char* num2, int length, char* result)
{
	// 0.处理异常情况
	if (num1 == NULL || num2 == NULL || length < 0 || result == NULL)
		return false;
	// 1.核心部分
	bool IsInc = false;
	for (int i = 0;i < length;i++)
	{
		int tmp1 = num1[length - 1 - i] - '0';
		int tmp2 = num2[length - 1 - i] - '0';
		int res;
		if (IsInc)
			res = tmp1 + tmp2 + 1;
		else
			res = tmp1 + tmp2;
		if (res >= 10)
		{
			IsInc = true;
			res -= 10;
		}
		else
		{
			IsInc = false;
		}
		result[length - i] = res + '0';
	}
	if (IsInc)
		result[0] = '1';
	else
		result[0] = '0';
	return true;
}

// 打印函数
void printResult(char* result, int length)
{
	// 0.处理异常情况
	if (result == NULL || length <= 0)
		return;
	// 1.核心部分
	// 从第一个不为'0'的数字打印起
	char* p = result;
	for (int i = 0;i < length;i++)
	{
		if (result[i] != '0')
			break;
		p++;

	}
	printf("%s\n", p);
}


int main()
{
	// 测试:
	// 正常情况
	// 边界情况
	// 异常情况
	//
	// 清空
	memset(num1, 0, 1001 * sizeof(char));
	memset(num2, 0, 1001 * sizeof(char));
	memset(result, 0, 1003 * sizeof(char));
	while (scanf("%s", num1) && scanf("%s", num2))
	{
		if (plus(num1, strlen(num1), num2, strlen(num2), result))
		{
			printResult(result, strlen(result));
		}
		// 清空
		memset(num1, 0, 1001 * sizeof(char));
		memset(num2, 0, 1001 * sizeof(char));
		memset(result, 0, 1003 * sizeof(char));
	}
	return 0;
}

