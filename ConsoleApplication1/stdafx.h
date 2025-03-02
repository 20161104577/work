// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "string"

struct player {
string player_name;//选手名字
string show_name;//节目名字
string sex;//选手性别
string category;//节目类型
string classroom;//班级信息
string phone;//手机号
double score;//成绩
};

typedef struct player NodePlayer;

struct Seqlist {
NodePlayer elem[100];
int last;
};

struct judges {
	string sex;
	string name;
	string phone;
};

typedef struct judges NodeJudges;

struct Judges {
	NodeJudges elem[100];
	int last;
};

string Trim(string& str);
void Menu(Seqlist* L, Judges* J);
//评委需要的函数judge.cpp
void menu2(Judges* J);
void add(Judges* J);
void Copy2(Judges* J);
void Load2(Judges* J);
void Show(Judges* J);
void Query2(Judges* J);
//选手需要的函数player.cpp
void menu1(Seqlist* L, Judges* J);
void Add(Seqlist* L);
void Del(Seqlist* L);
void Query1(Seqlist* L);
void Change(Seqlist* L);
void Show1(Seqlist* L);
void Sort(Seqlist* L);
void Copy1(Seqlist* L);
void Load1(Seqlist* L);
void Grade(Seqlist* L, Judges* J);
// TODO: 在此处引用程序需要的其他头文件
