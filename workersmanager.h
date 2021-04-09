#include<iostream>
#pragma once
using namespace std;
#include"boss.h"
#include"employee.h"
#include"manager.h"
#include"workers.h"
#include<fstream>
class workersmanager {
public:
	workersmanager();

	void show_menu();

	void add_emp();

	void exitsystem();

	int m_empnum;

	void modify_emp();

	int isexist(int id);

	void lookup_emp();

	workers **m_emparray;

	bool m_fileisempty;

	int get_empnum();
	void Clean_File();

	void sort_emp();

	void show_emp();

	void delete_emp();

	void init_emp();

	void  save();

	~workersmanager();
};