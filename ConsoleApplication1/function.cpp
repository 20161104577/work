#include "stdafx.h"

void UI()
{
	printf("\t\t\t|-----------------菜单-----------------|\n");
	printf("\t\t\t|------------1.进入选手信息系统--------|\n");
	printf("\t\t\t|------------2.进入评委信息系统--------|\n");
	printf("\t\t\t|------------0.退出系统----------------|\n");
}

string Trim(string& str)
{
	str.erase(0, str.find_first_not_of("\t\r\n"));
	str.erase(str.find_last_not_of("\t\r\n") + 1);
	return str;
}

void Menu(Seqlist* L, Judges* J)
{
	UI();//加载菜单 
	int i, have = 1;
	Load2(J);
	Load1(L);
	printf("选择要进行的功能：");
	while (cin>>i)
	{
		switch (i)
		{
		case 1: menu1(L, J); break;
		case 2: menu2(J); break;
		case 0: have = 0; break;
		}
		if (have == 0)
			break;
		UI();//加载菜单
		printf("选择要进行的功能：");
	}
}
