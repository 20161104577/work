#include "stdafx.h"

void UI()
{
	printf("\t\t\t|-----------------�˵�-----------------|\n");
	printf("\t\t\t|------------1.����ѡ����Ϣϵͳ--------|\n");
	printf("\t\t\t|------------2.������ί��Ϣϵͳ--------|\n");
	printf("\t\t\t|------------0.�˳�ϵͳ----------------|\n");
}

string Trim(string& str)
{
	str.erase(0, str.find_first_not_of("\t\r\n"));
	str.erase(str.find_last_not_of("\t\r\n") + 1);
	return str;
}

void Menu(Seqlist* L, Judges* J)
{
	UI();//���ز˵� 
	int i, have = 1;
	Load2(J);
	Load1(L);
	printf("ѡ��Ҫ���еĹ��ܣ�");
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
		UI();//���ز˵�
		printf("ѡ��Ҫ���еĹ��ܣ�");
	}
}
