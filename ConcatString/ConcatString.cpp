// ConcatString.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"

char str1[101],str2[101],result[201];

bool ConcatString(char* str1, int length1, char* str2, int length2,  char* result)
{
	// 0.处理异常情况
	if (str1 == NULL || str2 == NULL || result == NULL)
		return false;
	// 1.核心部分
	for (int i = 0;i < length1 + length2;i++)
	{
		if (i < length1) // 先拼接str1
		{
			result[i] = str1[i];
		}
		else //再拼接str2
		{
			result[i] = str2[i - length2];
		}
	}

	return true;
}

int main()
{
	// 测试
	// 异常情况
	// 边界情况
	// 正常情况
	memset(str1, '\0', 101*sizeof(char));
	memset(str2, '\0', 101*sizeof(char));
	memset(result, '\0', 101*sizeof(char));
	while (scanf("%s", str1) && scanf("%s", str2))
	{
		// 拼接str1和str2，并打印结果
		if (ConcatString(str1, strlen(str1), str2, strlen(str2), result))
		{
			printf("%s\n", result);
		}
		// 清空str1,str2,result
		memset(str1, '\0', 101 * sizeof(char));
		memset(str2, '\0', 101 * sizeof(char));
		memset(result, '\0', 101 * sizeof(char));
	}
    return 0;
}

