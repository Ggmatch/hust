// LargeIntegerOrder.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

// 思路:重写qsort中的compare函数，升序排列
// 1.长度不相同的，长的大
// 2.长度相同的，从高位往地位逐一比较

bool compare(string num1, string num2)
{
	// 1.长度不等，长的大;相等，则比较字符串大小
	if (num1.length() == num2.length())
		return num1<num2;
	else
		return num1.length()<num2.length();
}
string s[1000];

int main()
{
	int n;
	while(scanf("%d", &n)!=EOF)
	{
		//1.输入数据
		for (int i = 0;i < n;i++)
		{
			cin >> s[i];
		}
		// 2.排序
		sort(s, s + n, compare);
		// 3.打印结果
		for (int i = 0;i < n;i++)
		{
			cout << s[i] << endl;
		}
	}
    return 0;
}

