#include "stdafx.h"

string fileName = "judges.csv";

void Copy2(Judges* J)
{
	int i;
	ofstream file(fileName, ios::out);
	if (!file)
	{
		cout << "\t  文件打开失败！" << endl;
	}
	else
	{
		for (i = 0; i < J->last; i++)
		{
			file << J->elem[i].name << ","<< J->elem[i].sex << ","<< J->elem[i].phone << "\n";
		}
	}
}




void Load2(Judges* J)
{
	string str;
	int i = 1, j = 0, s = 0;
	ifstream file(fileName, ios::in);
	while (getline(file, str)) {
		istringstream sin(str);
		vector<string>fields;
		string field;
		while (getline(sin, field, ',')) {
			fields.push_back(field);
		}
		J->elem[s].name = Trim(fields[0]);
		J->elem[s].sex = Trim(fields[1]);
		J->elem[s].phone = Trim(fields[2]);
		s++;
	}
	J->last = s;
}

void UI2()
{
	printf("\t\t\t|-----------------菜单-----------------|\n");
	printf("\t\t\t|------------1.添加评委信息------------|\n");
	printf("\t\t\t|------------2.显示全部评委信息--------|\n");
	printf("\t\t\t|------------3.评委信息查询------------|\n");
	printf("\t\t\t|------------0.退出评委信息系统--------|\n");
}

void menu2(Judges* J)
{
	UI2();
	//	load2(J);//加载文件中评委数据
	int i, have = 1;
	printf("选择要进行的功能：");
	while (cin>>i)
	{
		have = 1;
		switch (i)
		{
		case 1: add(J); break;
		case 2: Show(J); break;
		case 3: Query2(J); break;
		case 0: have = 0; break;
		}
		Copy2(J);
		if (have == 0) {
			cout << "\t  裁判信息保存成功！" << endl;
			break;
			
		}	
		printf("选择要进行的功能：");
	}
}

void add(Judges* J)
{
	int i;
	i = J->last;
	printf("\t  进入评委添加系统。\n");
	printf("\t  输入评委名字：");
	cin>>J->elem[i].name;
	printf("\t  输入评委性别：");
	cin>>J->elem[i].sex;
	printf("\t  输入评委电话：");
	cin>>J->elem[i].phone;
	J->last++;
	cout << "\t  添加评委信息成功。" << endl;
}

void Show(Judges* J)
{
	printf("进入显示全部评委信息系统：\n");
	int i;
	printf("\t\t|      姓名      | 性别 |        电话号码        |\n");
	for (i = 0; i < J->last; i++)
	{
		cout << "\t\t|" << setw(16) << setfill(' ') << right << J->elem[i].name;
		cout << "|" << setw(6) << setfill(' ') << right << J->elem[i].sex;
		cout << "|" << setw(24) << setfill(' ') << right << J->elem[i].phone << "|" << endl;
		//cout<<"\t\t|     "<<J->elem[i].name<<"     |  "<<J->elem[i].sex<<"  |       "<<J->elem[i].phone<<"       |\n";
	}
		
}

int Find2(Judges* J)//查找函数，找到返回下标，找不到返回-1
{
	string Name;
	cout << "\t  请输入要查找的评委名字：";
	cin >> Name;
	int i = 0;
	while ((i < J->last) && !(J->elem[i].name == Name)) {
		i++;
	}
	if (i < J->last)
		return i;
	else
		return -1;
}

void Query2(Judges* J)
{
	cout << "\t  已进入评委信息查找系统"<<endl;
	int i;
	i = Find2(J);
	if (i != -1) {
		cout << "找到了" << J->elem[i].name << "评委的信息！" << endl;
		printf("\t\t|      姓名      | 性别 |        电话号码        |\n");
		cout << "\t\t|" << setw(16) << setfill(' ') << right << J->elem[i].name;
		cout << "|" << setw(6) << setfill(' ') << right << J->elem[i].sex;
		cout << "|" << setw(24) << setfill(' ') << right << J->elem[i].phone << "|" << endl;
	}
	else
		cout << "\t  抱歉，没有此人信息。" << endl;
		
}