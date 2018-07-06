#include "head.h"

void UI2()
{
	printf("\t\t\t|-----------------菜单-----------------|\n");
	printf("\t\t\t|------------1.评委信息查询------------|\n");
	printf("\t\t\t|------------2.显示全部评委信息--------|\n");
	printf("\t\t\t|------------0.退出评委信息系统--------|\n");
}

void load2(Judges* J)
{
	FILE *fp;
	int i=0, Sex;
	double Phone;
	char Name[20];
	fp = fopen("judges.csv","r");
	if(fp == NULL)
		printf("The file can't be opened！\n");
	else
	{
		while(fscanf(fp,"%s %d %lf",Name, &Sex, &Phone)!=EOF)
		{
			strcpy(J->elem[i].name,Name);
			J->elem[i].sex = Sex;
			J->elem[i].phone = Phone;
			i++;
			J->last++; 
		}
		J->last--;
		fclose(fp);
	}
}

void menu2(Judges* J)
{
	UI2();
	load2(J);//加载文件中评委数据
	int i,have = 1;
	printf("选择要进行的功能：");
	while(scanf("%d",&i)!=EOF)
	{
		have = 1;
		switch(i)
		{ 
			case 1: Query(J);break;
			case 2: Show(J);break;
			case 0: have = 0;break;
		}
		if(have == 0)
			break;
		printf("选择要进行的功能：");	
	}
}

int Find2(Judges* J)
{
	char Name[20];
	printf("请输入要查找评委的名字：\n");
	scanf("%s", Name);
	int i=0;        /*i为扫描计数器，初值为0，即从第一个元素开始比较*/
	while ((i <= J->last) && (strcmp(J->elem[i].name,Name)))		/*顺序扫描表，直到找到值为key的元素, 或扫描到表尾而没找到*/
		i++; 
	if(i<=J->last)
		return i;
	else 
		return -1;
}

void Query(Judges* J)//n为查找的学号 
{	
	printf("进入评委信息查找系统：\n");
	int i;
	i = Find2(J);
	if(i!=-1)
		printf("找到了！位置在%d处\n",i+1);  /*若找到值为e的元素，则返回其序号*/
	else
		printf("抱歉，没有找到。\n");  /*若没找到，则返回空序号*/
	
}

void Show(Judges* J)
{
	printf("进入显示全部评委信息系统：\n");
	int i;
	printf("\t\t|      姓名      | 性别 |        电话号码        |\n");//学号20位 名字12位 6 7 6 
	for(i=0; i<=J->last; i++)
	{
		if(J->elem[i].sex == 1)
			printf("\t\t|%16s|  男  |%24.0lf|\n",J->elem[i].name,J->elem[i].phone);
		else
			printf("\t\t|%16s|  女  |%240lf|\n",J->elem[i].name,J->elem[i].phone);
	}
}
