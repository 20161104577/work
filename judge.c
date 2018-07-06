#include "head.h"

void UI2()
{
	printf("\t\t\t|-----------------�˵�-----------------|\n");
	printf("\t\t\t|------------1.��ί��Ϣ��ѯ------------|\n");
	printf("\t\t\t|------------2.��ʾȫ����ί��Ϣ--------|\n");
	printf("\t\t\t|------------0.�˳���ί��Ϣϵͳ--------|\n");
}

void load2(Judges* J)
{
	FILE *fp;
	int i=0, Sex;
	double Phone;
	char Name[20];
	fp = fopen("judges.csv","r");
	if(fp == NULL)
		printf("The file can't be opened��\n");
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
	load2(J);//�����ļ�����ί����
	int i,have = 1;
	printf("ѡ��Ҫ���еĹ��ܣ�");
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
		printf("ѡ��Ҫ���еĹ��ܣ�");	
	}
}

int Find2(Judges* J)
{
	char Name[20];
	printf("������Ҫ������ί�����֣�\n");
	scanf("%s", Name);
	int i=0;        /*iΪɨ�����������ֵΪ0�����ӵ�һ��Ԫ�ؿ�ʼ�Ƚ�*/
	while ((i <= J->last) && (strcmp(J->elem[i].name,Name)))		/*˳��ɨ���ֱ���ҵ�ֵΪkey��Ԫ��, ��ɨ�赽��β��û�ҵ�*/
		i++; 
	if(i<=J->last)
		return i;
	else 
		return -1;
}

void Query(Judges* J)//nΪ���ҵ�ѧ�� 
{	
	printf("������ί��Ϣ����ϵͳ��\n");
	int i;
	i = Find2(J);
	if(i!=-1)
		printf("�ҵ��ˣ�λ����%d��\n",i+1);  /*���ҵ�ֵΪe��Ԫ�أ��򷵻������*/
	else
		printf("��Ǹ��û���ҵ���\n");  /*��û�ҵ����򷵻ؿ����*/
	
}

void Show(Judges* J)
{
	printf("������ʾȫ����ί��Ϣϵͳ��\n");
	int i;
	printf("\t\t|      ����      | �Ա� |        �绰����        |\n");//ѧ��20λ ����12λ 6 7 6 
	for(i=0; i<=J->last; i++)
	{
		if(J->elem[i].sex == 1)
			printf("\t\t|%16s|  ��  |%24.0lf|\n",J->elem[i].name,J->elem[i].phone);
		else
			printf("\t\t|%16s|  Ů  |%240lf|\n",J->elem[i].name,J->elem[i].phone);
	}
}
