#include <iostream>
#include <string>
#include <stdlib>

using namespace std;

struct player {
	int sex;//ѡ���Ա�  
	string player_name;//ѡ������ 
	string show_name;//��Ŀ���� 
	int category;//��Ŀ��� 
	int classroom;//�༶��Ϣ���ĸ����
	double phone;//�绰���룻
};

typedef struct player Node; 

struct Seqlist {
	Node elem[1000];
	int last;
};

typedef struct Seqlist* list;

struct judges {
	int sex;//�Ա�
	string name;//����
	double phone;//�绰���� 
};
