#pragma once
#include"boss.h"
boss::boss(int id, string name, int did) {
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;

}
void boss::showinfo() {
	cout << "ְ�����:" << this->m_id
		<< "\tְ������:" << this->m_name
		<< "\t��λ��" << this->getdeptname()
		<< "\t��λְ��ͳ��ȫ��˾" << endl;
}
string boss::getdeptname() {
	return string("�ܲ�");
}
