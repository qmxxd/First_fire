#pragma once
#include<iostream>
using namespace std;
#include"workers.h"
class manager :public workers
{
public:
	manager(int id, string name, int did);
	virtual void showinfo();
	virtual string getdeptname();

};