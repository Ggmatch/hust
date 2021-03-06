// ThreeMinStaffs.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

// 思路：重写qsort中的int compare(const void* , const void* )函数
// 按年龄，工号，姓名的优先级比较，升序操作

struct staff
{
	int number;
	string name;
	int age;
};

staff s[30];

int compare(const void* a, const void* b)
{
	// 0.强制类型转换
	staff* p1 = (staff*)a;
	staff* p2 = (staff*)b;
	// 1.比较年龄
	if (p1->age > p2->age)  //返回1，升序
	{
		return 1;
	}
	else if (p1->age < p2->age)
	{
		return -1;
	}
	else
	{
		// 2.比较工号
		if (p1->number > p2->number)
		{
			return 1;
		}
		else if (p1->number < p2->number)
		{
			return -1;
		}
		else
		{
			// 3.比较姓名
			if (p1->name > p2->name)
			{
				return 1;
			}
			else if (p1->name < p2->name)
			{
				return -1;
			}
			else
			{
				return 0;
			}
		}
	}
}

int main()
{
	int n;
	while (scanf("%d", &n))
	{
		// 输入数据
		for (int i = 0;i < n;i++)
		{
			cin >> s[i].number >> s[i].name >> s[i].age;
		}
		// 排序
		qsort(s, n, sizeof(staff), compare);
		// 打印结果
		for (int i = 0;i < 3;i++)
		{
			cout << s[i].number <<" "<< s[i].name <<" "<< s[i].age << endl;
		}
	}
    return 0;
}

