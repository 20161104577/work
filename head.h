#include <iostream>
#include <cstring>
#include <malloc.h>

using namespace std;

struct player {
	int sex;//ѡ���Ա�  
	string player_name;//ѡ������ 
	string show_name;//��Ŀ���� 
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
	string name;//����
	double phone;//�绰���� 
};

typedef struct judges NodeJudges;
struct Judges{
	NodeJudges elem[10];
	int last;
}; 

void menu(Seqlist* L);
