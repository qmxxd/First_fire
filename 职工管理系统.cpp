#include<iostream>
#include"workersmanager.h"
using namespace std;

int main() {
	workersmanager wm;
	int choice = 0;
	while (true)
	{ wm.show_menu();
		cout << "请输入您的选择：" << endl;
		cin>>choice;
		 switch (choice)
		 {
		 case 0://退出系统
			 wm.exitsystem();
			 break;
		 case 1://添加职工
			 wm.add_emp();
			 break;
		 case 2://显示职工
			 wm.show_emp();
			 break;
		 case 3://删除职工
			 wm.delete_emp();
			 break;
		 case 4://修改职工
			 wm.modify_emp();
		break;
		 case 5://查找职工
			 wm.lookup_emp();
			 break;
		 case 6://排序职工
			 wm.sort_emp();
			 break;
		 case 7://清空文档
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