#pragma once
#include<iostream>
using namespace std;
#include<string>
class workers {
public:
	virtual void showinfo() = 0;//��ʾ������Ϣ
	virtual string getdeptname() = 0;//��ʾְλ
	int m_id;
	string m_name;
	int m_deptid;
};  