// CMakeProject5.cpp : Defines the entry point for the application.
//

#include "CMakeProject5.h"

L p10(I d)
{
	L r = 1;
	for (; d; d--) r *= 10;
	R r;
}

L d2t(L v)
{
	L r = (v % 4) + 4;
	I j = 10;
	v /= 4;

	for(;v;j*=10,v/=4) r += ((v % 4) + 4)*j;

	R r;
}

L t2d(L t)
{
	L r = 0, rt = 0;
	I j = 1;

	for (;t;j*=4,t/=10) { rt = (t % 10) - 4; r += rt * j; }

	R r;
}

L rol(L t)
{
	I d = log(t) / log(10);
    L l = 0, r = t, p = p10(d);
	if (d > 1)
	{
		l = t % 10;
		r /= 10;
		r += (l * p);
	}

	R r;
}

L ror(L t)
{
	I d = log(t) / log(10);
    L l = 0, r = t, p = p10(d);
	if (d > 1)
	{
		l = t - (t % p);
		r -= l;
		l /= p;
		r *= 10;
		r += l;
	}

	R r;
}

I main(I n, C **a)
{
	M = calloc(65536, sizeof(M));
    A = (C*)malloc(747);
    B = (I*)malloc(128);
    A[654]='A';A[444]='B';A[476]='C';
    A[655]='D';A[445]='E';A[477]='F';
    A[656]='G';A[446]='H';A[544]='I';
    A[657]='J';A[447]='K';A[545]='L';
    A[664]='M';A[454]='N';A[546]='O';
    A[665]='P';A[455]='Q';A[547]='R';
    A[666]='S';A[456]='T';A[554]='U';
    A[667]='V';A[457]='X';A[555]='Y';
    A[674]='W';A[464]='Z';A[556]='!';
    A[675]='?';A[465]='.';A[557]=',';
    A[676]='$';A[466]='%';A[564]='/';
    A[677]='*';A[467]='(';A[565]=')';
    A[744]=':';A[474]=';';A[566]='[';
    A[745]=']';A[475]='{';A[567]='}';
    
	Od(rol(567));
	Od(ror(66343));
	Od(d2t(89));
	Od(d2t(0));
	Od(d2t(1));
	Od(d2t(2));
	Od(d2t(3));
	Od(t2d(0));
	Od(t2d(1));
	Od(t2d(2));
	Od(t2d(3));
	Od(t2d(77777777));
	R 0;
}
