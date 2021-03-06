// SortGrades.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>	
#include <string>
using namespace std;

// 学生信息结构体
struct Student
{
	string name;
	int age;
	int score;
};

Student s[1000];

// 思路：升序（小的在前）成绩 姓名 年龄
// 使用qsort，自定义compare函数

int compare(const void * p1, const void * p2)
{
	// 强制类型转换
	Student* a = (Student*)p1;
	Student* b = (Student*)p2;
	// 1.比较成绩
	if (a->score > b->score)  //前者比后者大，返回1
	{
		return 1;
	}
	else if(a->score < b->score)  //返回-1
	{
		return -1;
	}
	else  //相等
	{
		// 2.比较姓名
		if (a->name > b->name)  //前者比后者大，返回-1
		{
			return 1;
		}
		else if (a->name < b->name)  //返回-1
		{
			return -1;
		}
		else  //相等
		{
			// 3.比较年龄
			if (a->age > b->age)  //前者比后者大，返回1
			{
				return 1;
			}
			else if (a->age < b->age)  //返回-1
			{
				return -1;
			}
			else  //相等
			{
				return 0;
			}
		}
	}
}

int main()
{
	int num;
	while (scanf("%d", &num))
	{
		// 输入数据
		for (int i = 0;i < num;i++)
		{
			cin >> s[i].name >> s[i].age >> s[i].score;
		}
		// 排序
		qsort(s, num, sizeof(Student), compare);
		// 输出结果
		for (int i = 0;i < num;i++)
		{
			cout << s[i].name << " " << s[i].age << " " << s[i].score << "\n";
		}
	}
    return 0;
}

