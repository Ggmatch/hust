// CountCharsOfWords.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <cstring>
using namespace std;

#define MaxSize 50
char str[MaxSize];

int main()
{
	// 测试
	// 正常情况：|hello world a.  
	// 边界情况：|a.
	// 异常情况(不考虑多个'.'和'.'与最后一个单词离开）
	// 扩展性良好的思路：先根据空格‘分割’字符串，然后数每个char[]中的字符数量并打印
	// 一般思路：边识别边统计字符
	while (fgets(str,MaxSize,stdin))
	{
		bool IsInWord = false;  //判断是否在单词里
		int count = 0;  //统计每个单词的字符数
		int length = strlen(str);
		for (int i = 0;i < length;++i)
		{
			// 当在单词中碰到空格、字符或'.'的情况时
			if (IsInWord)
			{
				if (' ' == str[i]) // 空格
				{
					printf("%d ", count);
					IsInWord = true;
					count = 0;
				}
				else if ('.' == str[i])  // 结束（但无法确保只有'.'）
				{
					printf("%d\n", count);

				}
				else  // 字符
				{
					count++;
				}
			}
			else  // 不在单词中
			{
				// 遇到字符，即开始一个单词
				if (str[i] != ' ')  // 遇到字符
				{
					count++;
					IsInWord = true;
				}
				
			}

		}
	}
    return 0;
}

