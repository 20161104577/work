//#include "head.h"
//
//void UI1()
//{
//	printf("\t\t\t|-----------------�˵�-----------------|\n");
//	printf("\t\t\t|------------1.���ѡ����Ϣ------------|\n");
//	printf("\t\t\t|------------2.ɾ��ѡ����Ϣ------------|\n");
//	printf("\t\t\t|------------3.���ܳɼ�����------------|\n");
//	printf("\t\t\t|------------4.�ɼ���ѯ----------------|\n");
//	printf("\t\t\t|------------5.�޸�ѡ����Ϣ------------|\n");
//	printf("\t\t\t|------------6.��ʾȫ��ѧ����Ϣ--------|\n");
//	printf("\t\t\t|------------7.������ѧ����Ϣ----------|\n");
//	printf("\t\t\t|------------0.�˳�ѡ����Ϣϵͳ--------|\n");
//}
//void menu1(Seqlist* L)
//{
//	UI1();
//	load1(L);//�����ļ���ѡ������ 
//	int i;
//	printf("ѡ��Ҫ���еĹ��ܣ�");
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
//		L->last--;//����ȥ�࿪��һ��ĩβ���� 
//		fclose(fp);
//	}
//}
