#include "head.h"

int main()
{
	Seqlist L;
	Judges J;
	L.x = 0;
	L.last = 0;
	J.last = 4;
	Menu(&L, &J);
	return 0;
}
