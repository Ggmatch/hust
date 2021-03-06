// OddCheck.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#include "stdlib.h"

// 思想：1.计算出字符ASCII值所对应的二进制中1的个数；
//       2.若个数为偶数，则在首位加1，即加128
//       3.以二进制形式打印出结果
char data[101];
char result[10];

int countNumberOf1(char data)
{
	int tmp = (int)data;
	int tmp1;
	int count = 0;
	while (tmp)
	{
		tmp1 = tmp;
		count++;
		tmp -= 1;
		tmp = tmp & tmp1;
	}
	return count;
}

void printResult(int data)
{
	int tmp;
	for (int i = 0;i < 8;i++)
	{
		tmp = data % 2;
		result[7 - i] = tmp + '0';
		data /= 2;
	}
	printf("%s\n", result);
}



int main()
{
	// 清空 
	memset(data, 0, 101 * sizeof(char));
	memset(result, 0, 10 * sizeof(char));
	while (scanf("%s", data))
	{
		int len = strlen(data);
		
		for (int i = 0;i < len;i++)
		{
			int result = data[i];
			if (countNumberOf1(result) % 2 != 1)
			{
				result += 128;
			}
			printResult(result);
		}
		// 清空
		memset(data, 0, 101 * sizeof(char));
		memset(result, 0, 10 * sizeof(char));

	}
    return 0;
}

