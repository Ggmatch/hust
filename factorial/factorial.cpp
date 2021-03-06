// factorial.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*
	问题描述：输入n， 
	求y1=1!+3!+...m!(m是小于等于n的最大奇数） 
	y2=2!+4!+...p!(p是小于等于n的最大偶数)。
*/

#include <iostream>
using namespace std;
int main()
{
	int n, ans1, ans2, i, j;
	while (cin >> n) {
		ans1 = ans2 = 0, j = 1;
		for (i = 1; i <= n; ++i) {
			j *= i;
			if (i % 2) ans1 += j;
			else ans2 += j;
		}
		cout << ans1 << " " << ans2 << endl;
	}
}
