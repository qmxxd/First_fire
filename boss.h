#pragma once
#include<iostream>
using namespace std;
#include"workers.h"
class boss :public workers
{
public:
	boss(int id, string name, int did);
	virtual void showinfo();
	virtual string getdeptname();
};