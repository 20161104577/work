//#include <iostream>
//#include <cstring>
//#include <malloc.h>
//#include <cstdio> 
//
//using namespace std;

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct player {
	int sex;//ѡ���Ա�  
	char player_name[20];//ѡ������ 
	char show_name[20];//��Ŀ���� 
	int category;//��Ŀ��� 
	int classroom;//�༶��Ϣ���ĸ����
	double phone;//�绰���룻
};

typedef struct player NodePlayer; 

struct Seqlist {
	NodePlayer elem[1000];
	int last;
};

typedef struct Seqlist* list;
 
struct judges {
	int sex;//�Ա�
	char name[20];//����
	double phone;//�绰���� 
};

typedef struct judges NodeJudges;
struct Judges{
	NodeJudges elem[10];
	int last;
}; 

void Show(Judges* J);
void menu2(Judges* J);
void load2(Judges* J);
void Query(Judges* J);
void Menu(Seqlist* L,Judges* J);
