#include "head.h"
void UI()
{
	printf("\t\t\t|-----------------�˵�-----------------|\n");
	printf("\t\t\t|------------1.����ѡ����Ϣϵͳ--------|\n");
	printf("\t\t\t|------------2.������ί��Ϣϵͳ--------|\n");
	printf("\t\t\t|------------0.�˳�ϵͳ----------------|\n");
}


void Menu(Seqlist* L, Judges* J)
{
	UI();//���ز˵� 
	int i,have=1;
	printf("ѡ��Ҫ���еĹ��ܣ�");
	while(scanf("%d",&i)!=EOF)
	{
		switch(i)
		{ 
			case 1: menu1(L,J);break;
			case 2: menu2(J);break;
			case 0: have=0;break;
		}
		if(have==0)
			break;
		UI();//���ز˵�	
	}
}

