#pragma once
#include"workersmanager.h"
using namespace std;

workersmanager::workersmanager() {
	ifstream ifs;
	ifs.open("ְ�����ݿ�.txt", ios::in);
	//�ļ�������
	if (!ifs.is_open()) {
		//cout << "�ļ�������" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return ;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{//cout << "�ļ�Ϊ��" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	int num = this->get_empnum();
	this->m_empnum = num;
	this->m_emparray = new workers*[this->m_empnum];//���ٿռ�
	this->init_emp();
	this->m_fileisempty = false;
}
void workersmanager::delete_emp() {
	if (this->m_fileisempty) {
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
    cout << "��������ɾ����ְԱ��ţ�" << endl;
	int id;
	cin >> id;
	int index = this->isexist(id);
	if (index != -1) {
		for (index; index < this->m_empnum; index++)
		this->m_emparray[index] = this->m_emparray[index + 1];
		cout << "ɾ���ɹ���" << endl;
		this->m_empnum--;
		this->save();
	}
	else
	{
		cout << "δ���ҵ����Ϊ" << id << "��ְԱ" << endl;
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
			//�ҵ�ְ��
			index = i;
			break;
		}
	}
	return index;
}

void workersmanager::modify_emp() {
	if (this->m_fileisempty) 
		cout << "�ļ������ڻ�Ϊ��" << endl;
	else
	{
		cout << "�������޸�ְԱ�ı��" << endl;
		int id;
		cin >> id;
		int index = this->isexist(id);
		if (index != -1) {
			delete this->m_emparray[index];
			int did;
			string name;
			cout << "���޸ĸ�ְԱ��ţ�" << endl;
			cin >> id;
			int index = this->isexist(id);
			if (index != -1) {
				for (int i = 0; i < 100; i++) {
					cout << "������ͬ��ţ��������±��:" << endl;
					cin >> id;
					int index = this->isexist(id);
					if (index = -1)
						break;
			 }
			}
			cout << "���޸ĸ�ְԱ������" << endl;
			cin >> name;
			cout << "���޸ĸ�ְԱְλ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "2.�ܲ�" << endl;
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
			//�������� ��������
			this->m_emparray[index] = workers;
			cout << "�޸ĳɹ���" << endl;
			this->save();
		}
		else
		{
			cout << "δ���ҵ����Ϊ" << id << "��ְԱ" << endl;
		}
	}
	system("pause");
	system("cls");
}
int workersmanager::get_empnum() {//�õ�ԭ��ְԱ����
	ifstream ifs;
	ifs.open("ְ�����ݿ�.txt", ios::in);//���ļ�  ��
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		//ͳ����������
		num++;
	}
	return num;
}
void workersmanager::init_emp() {//�õ���ʼ��������
	ifstream ifs;
	ifs.open("ְ�����ݿ�.txt", ios::in);
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
void workersmanager::show_emp(){//��ʾְ��
	if (this->m_fileisempty) {
		cout << "�ļ������ڻ�Ϊ��" << endl;
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
	cout << "******��ӭʹ��ְ������ϵͳ��************" << endl;
	cout << "*********0.�˳�����ϵͳ*****************" << endl;
	cout << "*********1.����ְ����Ϣ*****************" << endl;
	cout << "*********2.��ʾְ����Ϣ*****************" << endl;
	cout << "*********3.ɾ����ְְ��*****************" << endl;
	cout << "*********4.�޸�ְ����Ϣ*****************" << endl;
	cout << "*********5.����ְ����Ϣ*****************" << endl;
	cout << "*********6.���ձ������*****************" << endl;
	cout << "*********7.��������ĵ�*****************" << endl;
	cout << "****************************************" << endl;
}
void workersmanager::exitsystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void workersmanager::add_emp() {
	cout << "���������ְ��������" << endl;
	int addnum = 0;//�����û�����������
	cin >> addnum;
	if (addnum > 0) {
		//���
		//�����µ���ӿռ��С
		int newsize = this->m_empnum + addnum;//�¿ռ��С=ԭ����¼����+��������
		//�����¿ռ�
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
			cout << "�������" << i + 1 << "λְ�����:" << endl;
			cin >> id;
			int index = this->isexist(id);
			if (index != -1) {
				for (int i = 0; i < 100; i++) {
					cout << "������ͬ��ţ��������±��:" << endl;
					cin >> id;
					int index = this->isexist(id);
					if (index = -1)
						break;
				}
			}
			cout << "�������" << i + 1 << "λְ������:" << endl;
			cin >> name;
			cout << "��ѡ���" << i + 1 << "λְ���ĸ�λ��"<< endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "2.�ܲ�" << endl;
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
		cout << "�ɹ����" << addnum << "����ְԱ" << endl;
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}
void workersmanager::save() {//�����ļ�
	ofstream ofs;
	ofs.open("ְ�����ݿ�.txt", ios::out);//������ķ�ʽ���ļ�

	//��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < this->m_empnum; i++) {
		ofs << this->m_emparray[i]->m_id << " "
			<< this->m_emparray[i]->m_name << " "
			<< this->m_emparray[i]->m_deptid << endl;
	}

	//�ر��ļ�
	ofs.close();
}
void workersmanager::Clean_File() {
	cout << "ȷ�������" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		//����ļ�
		ofstream ofs("ְ�����ݿ�.txt", ios::trunc);//ɾ���ļ������´���
		ofs.close();

		if (this->m_emparray != NULL) {

			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_empnum; i++) {
				delete this->m_emparray[i];
				this->m_emparray[i] = NULL;

			}
			//ɾ����������ָ��
			delete[] this->m_emparray;
			this->m_emparray = NULL;
			this->m_empnum = 0;
			this->m_fileisempty = true;
		}
		cout << "��ճɹ�" << endl;

	}
	system("pause");
	system("cls");

}
void workersmanager::sort_emp() {
	if (this->m_fileisempty)
		cout << "�ļ������ڻ�Ϊ��" << endl;
	else
	{ cout << "��ѡ���ŵ�����ʽ��" << endl;
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		int id;
		cin >> id;
		while (1) 
		{if (id == 1 || id == 2)
				break;
			cout << "������ѡ���ŵ�����ʽ��" << endl;
			cout << "1.����" << endl;
			cout << "2.����" << endl;
			cin >> id;
		}
		for (int i = 0; i < this->m_empnum; i++) {
			int minOrMax = i;//������Сֵ�����ֵ�±�
			for (int j = i + 1; j < this->m_empnum; j++) {
				if (id == 1) {//����
					if (this->m_emparray[minOrMax]->m_id > this->m_emparray[j]->m_id) {
						minOrMax = j;
					}
				}
				else {//����
					if (this->m_emparray[minOrMax]->m_id < this->m_emparray[j]->m_id) {
						minOrMax = j;
					}
				}
				//�ж�һ��ʼ�϶��� ��Сֵ�����ֵ �ǲ��� �������Сֵ�����ֵ��������ǽ���˳��
				if (i != minOrMax) {
					workers* temp = this->m_emparray[i];
					this->m_emparray[i] = this->m_emparray[minOrMax];
					this->m_emparray[minOrMax] = temp;
				}
			}
		}
		cout << "����ɹ��� �����Ľ��Ϊ��" << endl;
		this->save();//�����Ľ�����浽�ļ���
		this->show_emp();//չʾ����ְ��
		}
}

void workersmanager::lookup_emp() {
	if (this->m_fileisempty)
		cout << "�ļ������ڻ�Ϊ��" << endl;
	else
	{
		cout << "���������ְԱ�ı�ţ�" << endl;
		int id;
		cin >> id;
		int index = this->isexist(id);
		if (index != -1) {
			this->m_emparray[index]->showinfo();
		}
		else{
	 cout << "δ���ҵ����Ϊ" << id << "��ְԱ" << endl;
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
