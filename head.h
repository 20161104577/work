#include <iostream>
#include <cstring>
#include <malloc.h>
#include <cstdio> 

using namespace std;

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct player{
	int sex;//选手性别 
	char player_name[20];//选手名字 
	char show_name[20];//节目名字 
	int category;//节目类型 
	int classroom;//班级信息 
	double phone;//电话号码 
	int score;//成绩 
};

typedef struct player NodePlayer; 

struct Seqlist{
	NodePlayer elem[100];
	int last;
	int x;//节目类型数 
};

typedef struct Seqlist* list;
 
struct judges {
	int sex;//性别
	char name[20];//姓名
	double phone;//电话号码 
	
};

typedef struct judges NodeJudges;
struct Judges{
	NodeJudges elem[10];
	int last;
};
//选手
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
//裁判 
void Show(Judges* J);
void menu2(Judges* J);
void load2(Judges* J);
void Query(Judges* J);
void Menu(Seqlist* L,Judges* J);

