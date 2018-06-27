#include <iostream>
#include <string>
#include <stdlib>

using namespace std;

struct player {
	int sex;//选手性别  
	string player_name;//选手姓名 
	string show_name;//节目名称 
	int category;//节目类别 
	int classroom;//班级信息（哪个班的
	double phone;//电话号码；
};

typedef struct player Node; 

struct Seqlist {
	Node elem[1000];
	int last;
};

typedef struct Seqlist* list;

struct judges {
	int sex;//性别
	string name;//姓名
	double phone;//电话号码 
};
