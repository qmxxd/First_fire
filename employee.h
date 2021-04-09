#pragma once
#include<iostream>
using namespace std;
#include"workers.h"
class employee :public workers
{
public:
	employee(int id, string name, int did);
	virtual void showinfo();
	virtual string getdeptname();
	
};