// AplusB.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

// 思路：
// 1.把输入的数据字符串表示，换成long long形式
// 2.再整数相加减
// 3.打印结果
char s1[20], s2[20];

int main()
{
	while (scanf("%s%s", s1, s2) != EOF)
	{
		int m = 0;  //倍数
		// 1.遍历s1，转换为long long
		long long num1=0;
		int len1 = strlen(s1);
		for (int i = len1-1;i >= 0;i--)
		{
			// 2.是数字则加到num1中
			if (s1[i] >= '0'&&s1[i] <= '9')
			{
				num1 += (s1[i] - '0')*pow(10, m++);
			}
			else if (s1[i] == '-')  //3.是首位的-，则取反
			{
				num1 = -num1;
			}
		}
		m = 0;
		// 4.同样过程处理s2
		long long num2 = 0;
		int len2 = strlen(s2);
		for (int i = len2 - 1;i >= 0;i--)
		{
			// 2.是数字则加到num1中
			if (s2[i] >= '0'&&s2[i] <= '9')
			{
				num2 += (s2[i] - '0')*pow(10, m++);
			}
			else if (s2[i] == '-')  //3.是首位的-，则取反
			{
				num2 = -num2;
			}
		}

		// 5.num1和num2相加减
		long long result = num1 + num2;
		cout << result << "\n";
	}
    return 0;
}

