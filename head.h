#include <iostream>
#include <cstring>
#include <malloc.h>
#include <cstdio> 

using namespace std;

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct player{
	int sex;//ѡ���Ա� 
	char player_name[20];//ѡ������ 
	char show_name[20];//��Ŀ���� 
	int category;//��Ŀ���� 
	int classroom;//�༶��Ϣ 
	double phone;//�绰���� 
	int score;//�ɼ� 
};

typedef struct player NodePlayer; 

struct Seqlist{
	NodePlayer elem[100];
	int last;
	int x;//��Ŀ������ 
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
//ѡ��
void Laa(Seqlist* L);
void Add(Seqlist* L);
void Show1(Seqlist *L);
void menu1(Seqlist* L,Judges* J);
void copy(Seqlist* L);
void Query1(Seqlist* L);
void Change(Seqlist* L);
void Grade(Seqlist* L, Judges* J);
void Del(Seqlist* L);
void load1(Seqlist *L);
//���� 
void Show(Judges* J);
void menu2(Judges* J);
void load2(Judges* J);
void Query(Judges* J);
void Menu(Seqlist* L,Judges* J);

