// RepeatChar.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*
	问题描述：对给定的一个字符串，找出有重复的字符，并给出其位置
	如：abcaaAB12ab12 输出：a，1；a，4；a，5；a，10，b，2；b，11，1，8；1，12， 2，9；2，13。

*/

// 思路：哈希映射（一对多映射）,key为字符,value为其位置，建立一个result[256][100]的容器
// 1.遍历一遍，把<char,int>加入result中
// 2.遍历一遍result，把存在的字符及其位置全部打印出来

#include <cstdio>
#include <cstring>
using namespace std;

int result[256][105];

int main()
{
	char data[105];
	while (scanf("%s", data) != EOF)
	{
		//清空result并把每个key后的第一位改成计数器和插入位置记录器
		for (int i = 0;i < 256;i++)
			for (int j = 0;j < 105;j++)
				result[i][j] = 1;

		int len = strlen(data);
		for (int i = 0;i < len;i++)
		{
			//得到key
			int key = (int)data[i];
			//得到插入位置,并把插入位置往后移一位
			int index = result[key][0]++;
			//插入键值对
			result[key][index] = i;
		}
		//遍历，打印结果
		for (int i = 0;i < 256;i++)
		{
			//
			int end = result[i][0];
			for (int j = 1;j < end;j++)
			{
				char key = (char)i;
				int value = result[i][j];
				if (j == end - 1)
				{
					printf("%c:%d\n", key, value);
					break;
				}
				printf("%c:%d,", key, value);

			}
		}
	}
    return 0;
}

