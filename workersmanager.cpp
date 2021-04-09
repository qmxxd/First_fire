#pragma once
#include"workersmanager.h"
using namespace std;

workersmanager::workersmanager() {
	ifstream ifs;
	ifs.open("职工数据库.txt", ios::in);
	//文件不存在
	if (!ifs.is_open()) {
		//cout << "文件不存在" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return ;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{//cout << "文件为空" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	int num = this->get_empnum();
	this->m_empnum = num;
	this->m_emparray = new workers*[this->m_empnum];//开辟空间
	this->init_emp();
	this->m_fileisempty = false;
}
void workersmanager::delete_emp() {
	if (this->m_fileisempty) {
		cout << "文件不存在或为空" << endl;
	}
	else
	{
    cout << "请输入想删除的职员编号：" << endl;
	int id;
	cin >> id;
	int index = this->isexist(id);
	if (index != -1) {
		for (index; index < this->m_empnum; index++)
		this->m_emparray[index] = this->m_emparray[index + 1];
		cout << "删除成功！" << endl;
		this->m_empnum--;
		this->save();
	}
	else
	{
		cout << "未能找到编号为" << id << "的职员" << endl;
	}
	}
	
	system("pause");
	system("cls");
}
int workersmanager::isexist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_empnum; i++) {
		if (this->m_emparray[i]->m_id == id) {
			//找到职工
			index = i;
			break;
		}
	}
	return index;
}

void workersmanager::modify_emp() {
	if (this->m_fileisempty) 
		cout << "文件不存在或为空" << endl;
	else
	{
		cout << "请输入修改职员的编号" << endl;
		int id;
		cin >> id;
		int index = this->isexist(id);
		if (index != -1) {
			delete this->m_emparray[index];
			int did;
			string name;
			cout << "请修改该职员编号：" << endl;
			cin >> id;
			int index = this->isexist(id);
			if (index != -1) {
				for (int i = 0; i < 100; i++) {
					cout << "已有相同编号，请输入新编号:" << endl;
					cin >> id;
					int index = this->isexist(id);
					if (index = -1)
						break;
			 }
			}
			cout << "请修改该职员姓名：" << endl;
			cin >> name;
			cout << "请修改该职员职位：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "2.总裁" << endl;
			cin >> did;
			//this->m_emparray[index]->m_id = id;
			//this->m_emparray[index]->m_name = name;
			//this->m_emparray[index]->m_deptid= did; 
			workers* workers = NULL;
			switch (did)
			{
			case 1:
				workers = new employee(id, name, did);
				break;
			case 2:
				workers = new manager(id, name, did);
				break;
			case 3:
				workers= new boss(id, name, did);
				break;
			default:
				break;
			}
			//更新数据 到数组中
			this->m_emparray[index] = workers;
			cout << "修改成功！" << endl;
			this->save();
		}
		else
		{
			cout << "未查找到编号为" << id << "的职员" << endl;
		}
	}
	system("pause");
	system("cls");
}
int workersmanager::get_empnum() {//得到原有职员个数
	ifstream ifs;
	ifs.open("职工数据库.txt", ios::in);//打开文件  读
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		//统计人数变量
		num++;
	}
	return num;
}
void workersmanager::init_emp() {//得到初始化的数组
	ifstream ifs;
	ifs.open("职工数据库.txt", ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{   workers *workers = NULL;
		if (did == 1) {
			workers = new employee(id, name, did);
		}
		else if(did==2)
		{
			workers = new manager(id, name, did);
		}
		else if(did==3)
		{
			workers = new boss(id, name, did);
		}
		this->m_emparray[index] = workers;
		index++;
	}
	ifs.close();
}
void workersmanager::show_emp(){//显示职工
	if (this->m_fileisempty) {
		cout << "文件不存在或为空" << endl;
  }
	else
	{
		for (int i = 0; i < this->m_empnum; i++) {
			this->m_emparray[i]->showinfo();
		}

	}
	system("pause");
	system("cls");

}
void workersmanager::show_menu() {
	cout << "****************************************" << endl;
	cout << "******欢迎使用职工管理系统！************" << endl;
	cout << "*********0.退出管理系统*****************" << endl;
	cout << "*********1.增加职工信息*****************" << endl;
	cout << "*********2.显示职工信息*****************" << endl;
	cout << "*********3.删除离职职工*****************" << endl;
	cout << "*********4.修改职工信息*****************" << endl;
	cout << "*********5.查找职工信息*****************" << endl;
	cout << "*********6.按照编号排序*****************" << endl;
	cout << "*********7.清空所有文档*****************" << endl;
	cout << "****************************************" << endl;
}
void workersmanager::exitsystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void workersmanager::add_emp() {
	cout << "请输入添加职工数量：" << endl;
	int addnum = 0;//保存用户的输入数量
	cin >> addnum;
	if (addnum > 0) {
		//添加
		//计算新的添加空间大小
		int newsize = this->m_empnum + addnum;//新空间大小=原来记录人数+新增人数
		//开辟新空间
		workers** newspace = new workers *[newsize];
		if (this->m_emparray != 0) {
			for (int i = 0; i < this->m_empnum; i++) {
				newspace[i] = this->m_emparray[i];
			}
		}
		for (int i=0; i < addnum; i++) {
			int id;
			int did;
			string name;
			cout << "请输入第" << i + 1 << "位职工编号:" << endl;
			cin >> id;
			int index = this->isexist(id);
			if (index != -1) {
				for (int i = 0; i < 100; i++) {
					cout << "已有相同编号，请输入新编号:" << endl;
					cin >> id;
					int index = this->isexist(id);
					if (index = -1)
						break;
				}
			}
			cout << "请输入第" << i + 1 << "位职工姓名:" << endl;
			cin >> name;
			cout << "请选择第" << i + 1 << "位职工的岗位："<< endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "2.总裁" << endl;
			cin >> did;
			workers*workers = NULL;
			switch (did)
			{
			case 1:
				workers = new employee(id, name, 1);
				break;
			case 2:workers = new manager(id, name, 3);
				break;
			case 3:workers = new boss(id, name, 3);
				break;
			default:
				break;
			}
			newspace[this->m_empnum + i] = workers;
		}
		this->m_fileisempty = false;
		delete []this->m_emparray;
		this->m_emparray = newspace;
		this->m_empnum = newsize;
		cout << "成功添加" << addnum << "名新职员" << endl;
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}
void workersmanager::save() {//保存文件
	ofstream ofs;
	ofs.open("职工数据库.txt", ios::out);//用输出的方式打开文件

	//将每个人的数据写入到文件中
	for (int i = 0; i < this->m_empnum; i++) {
		ofs << this->m_emparray[i]->m_id << " "
			<< this->m_emparray[i]->m_name << " "
			<< this->m_emparray[i]->m_deptid << endl;
	}

	//关闭文件
	ofs.close();
}
void workersmanager::Clean_File() {
	cout << "确认清空吗？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		//清空文件
		ofstream ofs("职工数据库.txt", ios::trunc);//删除文件后重新创建
		ofs.close();

		if (this->m_emparray != NULL) {

			//删除堆区的每个职工对象
			for (int i = 0; i < this->m_empnum; i++) {
				delete this->m_emparray[i];
				this->m_emparray[i] = NULL;

			}
			//删除堆区数组指针
			delete[] this->m_emparray;
			this->m_emparray = NULL;
			this->m_empnum = 0;
			this->m_fileisempty = true;
		}
		cout << "清空成功" << endl;

	}
	system("pause");
	system("cls");

}
void workersmanager::sort_emp() {
	if (this->m_fileisempty)
		cout << "文件不存在或为空" << endl;
	else
	{ cout << "请选择编号的排序方式：" << endl;
		cout << "1.降序" << endl;
		cout << "2.升序" << endl;
		int id;
		cin >> id;
		while (1) 
		{if (id == 1 || id == 2)
				break;
			cout << "请重新选择编号的排序方式：" << endl;
			cout << "1.降序" << endl;
			cout << "2.升序" << endl;
			cin >> id;
		}
		for (int i = 0; i < this->m_empnum; i++) {
			int minOrMax = i;//声明最小值或最大值下标
			for (int j = i + 1; j < this->m_empnum; j++) {
				if (id == 1) {//升序
					if (this->m_emparray[minOrMax]->m_id > this->m_emparray[j]->m_id) {
						minOrMax = j;
					}
				}
				else {//降序
					if (this->m_emparray[minOrMax]->m_id < this->m_emparray[j]->m_id) {
						minOrMax = j;
					}
				}
				//判断一开始认定的 最小值或最大值 是不是 计算的最小值或最大值，如果不是交换顺序
				if (i != minOrMax) {
					workers* temp = this->m_emparray[i];
					this->m_emparray[i] = this->m_emparray[minOrMax];
					this->m_emparray[minOrMax] = temp;
				}
			}
		}
		cout << "排序成功！ 排序后的结果为：" << endl;
		this->save();//排序后的结果保存到文件中
		this->show_emp();//展示所有职工
		}
}

void workersmanager::lookup_emp() {
	if (this->m_fileisempty)
		cout << "文件不存在或为空" << endl;
	else
	{
		cout << "请输入查找职员的编号：" << endl;
		int id;
		cin >> id;
		int index = this->isexist(id);
		if (index != -1) {
			this->m_emparray[index]->showinfo();
		}
		else{
	 cout << "未查找到编号为" << id << "的职员" << endl;
		}
	}
	system("pause");
	system("cls");
}
workersmanager::~workersmanager() {
	if (this->m_emparray != NULL) {
		delete[] this->m_emparray;
		this->m_emparray = NULL;
	}
}
