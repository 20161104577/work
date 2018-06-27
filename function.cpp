#include "head.h"

void load(Seqlist *L)
{
	int i = 0, Sex, Category, Classroom;
	double Phone;
	string Playname, Showname;
	FILE* fp;
	fp = fopen("player.csv", "r");
	if(fp == NULL)
		printf("The file can't be opened!\n");
	else
	{
		while(fscanf(fp,"%s %d %s %d %d %lf",Playname, &Sex, Showname, &Category, &Classroom, &Phone)!=EOF)
		{
			strcpy(L->elem[i].player_name,Playname);
			L->elem[i].sex = Sex;
			strcpy(L->elem[i].show_name,Showname);
			L->elem[i].category = Category;
			L->elem[i].classroom = Classroom;
			L->elem[i].phone = Phone;
			i++;
			L->last++;
		}
		L->last--;//最后剪去多开的一个末尾数组 
		fclose(fp);
	}
}

void menu(Seqlist* L)
{
//	UI();//加载菜单 
	load(L);//加载文件中学生数据 
	int i;
	cout<<"选择要进行的功能：";
	while(cin>>i)
	{
		switch(i)
		{ 
			case 1: Show(L);break;
		}
			
	}
}

