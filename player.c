//#include "head.h"
//
//void UI1()
//{
//	printf("\t\t\t|-----------------菜单-----------------|\n");
//	printf("\t\t\t|------------1.添加选手信息------------|\n");
//	printf("\t\t\t|------------2.删除选手信息------------|\n");
//	printf("\t\t\t|------------3.对总成绩排名------------|\n");
//	printf("\t\t\t|------------4.成绩查询----------------|\n");
//	printf("\t\t\t|------------5.修改选手信息------------|\n");
//	printf("\t\t\t|------------6.显示全部学生信息--------|\n");
//	printf("\t\t\t|------------7.插入新学生信息----------|\n");
//	printf("\t\t\t|------------0.退出选手信息系统--------|\n");
//}
//void menu1(Seqlist* L)
//{
//	UI1();
//	load1(L);//加载文件中选手数据 
//	int i;
//	printf("选择要进行的功能：");
//	while(scanf("%d",&i)!=EOF)
//	{
//		switch(i)
//		{ 
//			case 1: Add(L);break;
//			case 2: Del(L);break;
//			case 3: Sort(L);break;
//			case 4: Query(L);break;
//			case 5: Change(L);break;
//			case 6: Show(L);break;
//			case 7: Insert(L);break;
//			case 0: Menu();break;
//		}
//			
//	}
//}
//
//void load1(Seqlist *L)
//{
//	int i = 0, Sex, Category, Classroom;
//	double Phone;
//	char Playname[20], Showname[20];
//	if(fp == NULL)
//		printf("The file can't be opened!\n");
//	else
//	{
//		while(fscanf(fp,"%s %d %s %d %d %lf",Playname, &Sex, Showname, &Category, &Classroom, &Phone)!=EOF)
//		{
//			strcpy(L->elem[i].player_name,Playname);
//			L->elem[i].sex = Sex;
//			strcpy(L->elem[i].show_name,Showname);
//			L->elem[i].category = Category;
//			L->elem[i].classroom = Classroom;
//			L->elem[i].phone = Phone;
//			i++;
//			L->last++;
//		}
//		L->last--;//最后剪去多开的一个末尾数组 
//		fclose(fp);
//	}
//}
