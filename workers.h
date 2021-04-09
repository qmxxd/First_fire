#pragma once
#include<iostream>
using namespace std;
#include<string>
class workers {
public:
	virtual void showinfo() = 0;//显示个人信息
	virtual string getdeptname() = 0;//显示职位
	int m_id;
	string m_name;
	int m_deptid;
};  