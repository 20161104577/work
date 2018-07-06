#include "head.h"

char cate[10][10];//��Ŀ���ͣ�
void UI1()
{
	printf("\t\t\t|-----------------�˵�-----------------|\n");
	printf("\t\t\t|------------1.���ѡ����Ϣ------------|\n");
	printf("\t\t\t|------------2.ɾ��ѡ����Ϣ------------|\n");
	printf("\t\t\t|------------3.���ܳɼ�����------------|\n");
	printf("\t\t\t|------------4.�ɼ���ѯ----------------|\n");
	printf("\t\t\t|------------5.�޸�ѡ����Ϣ------------|\n");
	printf("\t\t\t|------------6.��ʾȫ��ѡ����Ϣ--------|\n");
	printf("\t\t\t|------------7.��ѡ�ֽ��д��----------|\n");
	printf("\t\t\t|------------0.�˳�ѡ����Ϣϵͳ--------|\n");
}
void menu1(Seqlist* L,Judges* J)
{
	UI1();
	load1(L);//�����ļ��е�ѡ������
	Laa(L);
	int i,have=1;
	printf("ѡ��Ҫ���еĹ��ܣ�");
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
		printf("\nѡ��Ҫ���еĹ��ܣ�");
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
	printf("�ѽ���ѡ����Ϣ��ʾϵͳ������ʾȫ��ѡ����Ϣ��\n");
	printf("| ѡ������ | ѡ���Ա� | ��Ŀ���� | ��Ŀ���� | �༶��Ϣ |    �绰����    | �ɼ� |\n"); 
	int i;
	for(i=0; i<L->last; i++)
	{
		if(L->elem[i].sex==1)
			printf("|%10s|    ��    |%10s|",L->elem[i].player_name, L->elem[i].show_name);
		else
			printf("|%10s|    Ů    |%10s|",L->elem[i].player_name, L->elem[i].show_name);
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
		printf("����ɹ���\n");
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
	printf("����ѡ����Ϣ���ϵͳ.\n");
	i = L->last;
	printf("����ѡ�����֣�");
	scanf("%s",L->elem[i].player_name);
	printf("����ѡ���Ա�(��������1��Ů������0)");
	scanf("%d",&L->elem[i].sex);
	
	printf("����ѡ�ֵĽ�Ŀ���ͣ�");
	scanf("%d",&L->elem[i].category);
	if(L->elem[i].category >= L->x)
	{
		printf("�޴˽�Ŀ���ͣ����Ϊ�½�Ŀ���͡�\n�������Ŀ�������ƣ�");
		L->x++;
		scanf("%s",name);
		strcpy(cate[L->x],name);
		printf("����½�Ŀ���ͳɹ���\n"); 
	}
	printf("����ѡ�ֵĽ�Ŀ���ƣ�");
	scanf("%s",L->elem[i].show_name); 
	printf("����ѡ�ְ༶��Ϣ��"); 
	scanf("%d",&L->elem[i].classroom);
	printf("����ѡ�ֵ绰��");
	scanf("%lf",&L->elem[i].phone);
	L->elem[i].score = -1;
	printf("ѡ��%s����Ϣ��ӳɹ���\n",L->elem[i].player_name);
	L->last++;
}

int Find(Seqlist* L)//���ڲ���ѡ�ֲ����������ڵ�λ�� 
{
	char name[20];
	int i = 0;
	printf("������Ҫ���ҵ�ѡ��������");
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
	int num;//��ί��
	num = J->last;
	
	s = Find(L);
	if(s == -1)
		printf("δ�ҵ�ѡ����Ϣ��\n");
	else
	{
		printf("������%sѡ�ֽ��д�֡�\n������ί��ֳɼ�����%d����ί��\n",L->elem[s].player_name, num);
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
	printf("����ѡ����Ϣ�޸�ϵͳ��\n");
	int i, s, have;
	s = Find(L);
	if(s == -1)
		printf("δ�ҵ�ѡ����Ϣ��\n");
	else
	{
		printf("�����޸�%sѡ����Ϣ��\n",L->elem[s].player_name);
		printf("ѡ��Ҫ�޸ĵ���Ϣ��1.�޸Ľ�Ŀ���� 2.�޸Ľ�Ŀ���� 3.�޸İ༶��Ϣ 4.�޸ĵ绰����\n");
		scanf("%d",&have);
		switch(have)
		{
			case 1:scanf("%s",L->elem[s].show_name);break;
			case 2:scanf("%d",&L->elem[s].category);break;
			case 3:scanf("%d",&L->elem[s].classroom);break;
			case 4:scanf("%lf",&L->elem[s].phone);break;
		}
		printf("�޸ĳɹ���\n");	
	 } 
	
}

void Query1(Seqlist* L)
{
	printf("����ѡ����Ϣ��ѯϵͳ��\n");
	int s = Find(L);
	if(s==-1)
		printf("δ�ҵ�ѡ����Ϣ��\n");
	else
	{
		printf("�ҵ���%sѡ��\n",L->elem[s].player_name);
		printf("| ѡ������ | ѡ���Ա� | ��Ŀ���� | ��Ŀ���� | �༶��Ϣ |    �绰����    | �ɼ� |\n"); 
		if(L->elem[s].sex==1)
			printf("|%10s|    ��    |%10s|",L->elem[s].player_name, L->elem[s].show_name);
		else
			printf("|%10s|    Ů    |%10s|",L->elem[s].player_name, L->elem[s].show_name);
		printf("%10s",cate[L->elem[s].category]);
		printf("|%10d|%16.0lf|%6d|\n",L->elem[s].classroom, L->elem[s].phone, L->elem[s].score);	
	}

}

void Del(Seqlist* L)
{
	printf("�ѽ���ѡ����Ϣɾ��ϵͳ\n");
	int s,i;
	s = Find(L);
	if(s == -1)
		printf("δ�ҵ�ѡ����Ϣ��\n");
	else
	{
		for(i=s; i<L->last; i++)
			L->elem[i] = L->elem[i+1];
		L->last--;
		printf("\tɾ���ɹ�\n");	
	}
	
}
