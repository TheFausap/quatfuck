// CMakeProject5.cpp : Defines the entry point for the application.
//

#include "CMakeProject5.h"

int d2t(int v)
{
	int r = (v % 4) + 4;
	int j = 10;
	v /= 3;

	for(;v;j*=10,v/=3) r += ((v % 4) + 4)*j;

	return r;
}

int t2d(int t)
{
	int r = 0, rt = 0;
	int j = 1;

	for (;t;j*=4,t/=10) { rt = (t % 10) - 4; r += rt * j; }

	return r;
}

int rol(int t)
{
	int d = log(t) / log(10);
	d++;
	int l = 0, r = t;
	if (d > 1)
	{
		l = d % 10;
		r -= l;
		r += (l * d);
	}

	return r;
}

I main(I n, C **a)
{
	Od(d2t(0));
	Od(d2t(4));
	Od(d2t(5));
	Od(d2t(10));
	Od(d2t(17339));
	Od(t2d(56));
	Od(t2d(rol(56)));
	Od(t2d(3));
	R 0;
}
