#include "head.h"

char cate[10][10];//节目类型；
void UI1()
{
	printf("\t\t\t|-----------------菜单-----------------|\n");
	printf("\t\t\t|------------1.添加选手信息------------|\n");
	printf("\t\t\t|------------2.删除选手信息------------|\n");
	printf("\t\t\t|------------3.对总成绩排名------------|\n");
	printf("\t\t\t|------------4.成绩查询----------------|\n");
	printf("\t\t\t|------------5.修改选手信息------------|\n");
	printf("\t\t\t|------------6.显示全部选手信息--------|\n");
	printf("\t\t\t|------------7.对选手进行打分----------|\n");
	printf("\t\t\t|------------0.退出选手信息系统--------|\n");
}
void menu1(Seqlist* L,Judges* J)
{
	UI1();
	load1(L);//加载文件中的选手数据
	Laa(L);
	int i,have=1;
	printf("选择要进行的功能：");
	while(scanf("%d",&i)!=EOF)
	{
		switch(i)
		{
			case 1:Add(L);break;
			case 2:Del(L);break;
			case 4:Query1(L);break;
			case 5:Change(L);break;
			case 6:Show1(L);break;
			case 7:Grade(L,J);break;
			case 0:have = 0;break;
		}
		if(have==0)
			break;
		printf("\n选择要进行的功能：");
	 }
	 copy(L);
}


//			case 1: Add(L);break;
//			case 2: Del(L);break;
//		//	case 3: Sort(L);break;
//		//	case 4: Query(L);break;
//		//	case 5: Change(L);break;
//			case 6: Show(L);break;
//		//	case 7: Insert(L);break;
//		//	case 0: Menu();break;

void Show1(Seqlist *L)
{
	printf("已进入选手信息显示系统，将显示全部选手信息：\n");
	printf("| 选手名字 | 选手性别 | 节目名称 | 节目类型 | 班级信息 |    电话号码    | 成绩 |\n"); 
	int i;
	for(i=0; i<L->last; i++)
	{
		if(L->elem[i].sex==1)
			printf("|%10s|    男    |%10s|",L->elem[i].player_name, L->elem[i].show_name);
		else
			printf("|%10s|    女    |%10s|",L->elem[i].player_name, L->elem[i].show_name);
		printf("%10s",cate[L->elem[i].category]);
		printf("|%10d|%16.0lf|%6d|\n",L->elem[i].classroom, L->elem[i].phone, L->elem[i].score);
	}
}
void copy(Seqlist* L)
{
	int i;
	FILE *fp;
	fp = fopen("player.csv","w");
	if(fp == NULL)
		printf("The file can't be opened!\n");
	else
	{
		for(i=0; i<L->last; i++)
		{
			fprintf(fp,"%s %d %s %d %d %lf %d\n",L->elem[i].player_name, L->elem[i].sex, L->elem[i].show_name, L->elem[i].category, L->elem[i].classroom,L->elem[i].phone,L->elem[i].score);
		}
		printf("保存成功！\n");
		fclose(fp);
	}
	
}

void Laa(Seqlist* L)
{
	FILE* fp;
	int X;
	fp = fopen("x.txt","r");
	fscanf(fp,"%d",X);
	L->x = X;
	fclose(fp);
}

void load1(Seqlist *L)
{
	int i = 0, Sex, Category, Score, Classroom;
	double Phone;
	char Playname[20], Showname[20];
	FILE* fp;
	fp = fopen("player.csv","r");
	if(fp == NULL)
		printf("The file can't be opened!\n");
	else
	{
		while(fscanf(fp,"%s %d %s %d %d %lf %d",Playname, &Sex, Showname, &Category, &Classroom, &Phone, &Score)!=EOF)
		{
			strcpy(L->elem[i].player_name,Playname);
			L->elem[i].sex = Sex;
			strcpy(L->elem[i].show_name,Showname);
			L->elem[i].category = Category;
			L->elem[i].classroom = Classroom;
			L->elem[i].phone = Phone;
			L->elem[i].score = Score;
			i++;
			L->last++;
		}
		fclose(fp);
	}
}

void Add(Seqlist* L)
{	
	char name[20];
 	int i;
	printf("进入选手信息添加系统.\n");
	i = L->last;
	printf("输入选手名字：");
	scanf("%s",L->elem[i].player_name);
	printf("输入选手性别：(男生输入1，女生输入0)");
	scanf("%d",&L->elem[i].sex);
	
	printf("输入选手的节目类型：");
	scanf("%d",&L->elem[i].category);
	if(L->elem[i].category >= L->x)
	{
		printf("无此节目类型，添加为新节目类型。\n请输入节目类型名称：");
		L->x++;
		scanf("%s",name);
		strcpy(cate[L->x],name);
		printf("添加新节目类型成功。\n"); 
	}
	printf("输入选手的节目名称：");
	scanf("%s",L->elem[i].show_name); 
	printf("输入选手班级信息："); 
	scanf("%d",&L->elem[i].classroom);
	printf("输入选手电话：");
	scanf("%lf",&L->elem[i].phone);
	L->elem[i].score = -1;
	printf("选手%s的信息添加成功！\n",L->elem[i].player_name);
	L->last++;
}

int Find(Seqlist* L)//用于查找选手并返回其所在的位置 
{
	char name[20];
	int i = 0;
	printf("请输入要查找的选手姓名：");
	scanf("%s",name);
	while((i<L->last)&&(strcmp(L->elem[i].player_name,name)))
		i++;
	if(i<L->last)
		return i;
	else
		return -1;
}

void Grade(Seqlist* L, Judges* J)
{
	int s, i, min, max, sum = 0;
	int score[10];
	int num;//评委数
	num = J->last;
	
	s = Find(L);
	if(s == -1)
		printf("未找到选手信息。\n");
	else
	{
		printf("即将对%s选手进行打分。\n输入评委打分成绩（共%d个评委）\n",L->elem[s].player_name, num);
		for(i=0; i<J->last; i++)
		{
			scanf("%d", &score[i]);
			sum += score[i];
		}
		min = score[0];
		max = score[0];
		for(i=0; i<J->last; i++)
		{
			if(score[i]<min)
				min = score[i];
			if(score[i]>max)
				max = score[i];
		}
		sum = sum - max;
		sum = sum - min;
		sum = sum/(J->last-2);
		L->elem[s].score = sum;
	}
}

void Change(Seqlist* L)
{
	printf("进入选手信息修改系统。\n");
	int i, s, have;
	s = Find(L);
	if(s == -1)
		printf("未找到选手信息。\n");
	else
	{
		printf("即将修改%s选手信息。\n",L->elem[s].player_name);
		printf("选择要修改的信息：1.修改节目名字 2.修改节目类型 3.修改班级信息 4.修改电话号码\n");
		scanf("%d",&have);
		switch(have)
		{
			case 1:scanf("%s",L->elem[s].show_name);break;
			case 2:scanf("%d",&L->elem[s].category);break;
			case 3:scanf("%d",&L->elem[s].classroom);break;
			case 4:scanf("%lf",&L->elem[s].phone);break;
		}
		printf("修改成功！\n");	
	 } 
	
}

void Query1(Seqlist* L)
{
	printf("进入选手信息查询系统。\n");
	int s = Find(L);
	if(s==-1)
		printf("未找到选手信息！\n");
	else
	{
		printf("找到了%s选手\n",L->elem[s].player_name);
		printf("| 选手名字 | 选手性别 | 节目名称 | 节目类型 | 班级信息 |    电话号码    | 成绩 |\n"); 
		if(L->elem[s].sex==1)
			printf("|%10s|    男    |%10s|",L->elem[s].player_name, L->elem[s].show_name);
		else
			printf("|%10s|    女    |%10s|",L->elem[s].player_name, L->elem[s].show_name);
		printf("%10s",cate[L->elem[s].category]);
		printf("|%10d|%16.0lf|%6d|\n",L->elem[s].classroom, L->elem[s].phone, L->elem[s].score);	
	}

}

void Del(Seqlist* L)
{
	printf("已进入选手信息删除系统\n");
	int s,i;
	s = Find(L);
	if(s == -1)
		printf("未找到选手信息！\n");
	else
	{
		for(i=s; i<L->last; i++)
			L->elem[i] = L->elem[i+1];
		L->last--;
		printf("\t删除成功\n");	
	}
	
}
