// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	Seqlist L;
	Judges J;
	L.last = 0;
	J.last = 0;
	Menu(&L, &J);
	return 0;
}