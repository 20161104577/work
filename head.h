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
	int sex;//选手性别  
	char player_name[20];//选手姓名 
	char show_name[20];//节目名称 
	int category;//节目类别 
	int classroom;//班级信息（哪个班的
	double phone;//电话号码；
};

typedef struct player NodePlayer; 

struct Seqlist {
	NodePlayer elem[1000];
	int last;
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

void Show(Judges* J);
void menu2(Judges* J);
void load2(Judges* J);
void Query(Judges* J);
void Menu(Seqlist* L,Judges* J);
