#include<iostream>
#include"workersmanager.h"
using namespace std;

int main() {
	workersmanager wm;
	int choice = 0;
	while (true)
	{ wm.show_menu();
		cout << "����������ѡ��" << endl;
		cin>>choice;
		 switch (choice)
		 {
		 case 0://�˳�ϵͳ
			 wm.exitsystem();
			 break;
		 case 1://���ְ��
			 wm.add_emp();
			 break;
		 case 2://��ʾְ��
			 wm.show_emp();
			 break;
		 case 3://ɾ��ְ��
			 wm.delete_emp();
			 break;
		 case 4://�޸�ְ��
			 wm.modify_emp();
		break;
		 case 5://����ְ��
			 wm.lookup_emp();
			 break;
		 case 6://����ְ��
			 wm.sort_emp();
			 break;
		 case 7://����ĵ�
			 wm.Clean_File();
			 break;
		 default:
			 system("cls");
			 break;
		 }

	}
	system("pause");
	return 0;

}