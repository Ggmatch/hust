// CountCharsOfWords.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
using namespace std;

#define MaxSize 50
char str[MaxSize];

int main()
{
	// 测试
	// 正常情况：|hello world.
	// 边界情况：| hello world.
	// 异常情况
	// 扩展性良好的思路：先根据空格‘分割’字符串，然后数每个char[]中的字符数量并打印
	// 一般思路：边识别边统计字符
	while (gets(str))
	{
		int i = 0;
	}
    return 0;
}

