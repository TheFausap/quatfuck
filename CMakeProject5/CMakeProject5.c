// CMakeProject5.cpp : Defines the entry point for the application.
//

#include "CMakeProject5.h"

L p10(I d)
{
	L r = 1;
	for (; d; d--) r *= 10;
	R r;
}

I d2t(I v)
{
	I r = (v % 4) + 4;
	I j = 10;
	v /= 4;

	for(;v;j*=10,v/=4) r += ((v % 4) + 4)*j;

	R r;
}

I t2d(I t)
{
	I r = 0, rt = 0;
	I j = 1;

	for (;t;j*=4,t/=10) { rt = (t % 10) - 4; r += rt * j; }

	R r;
}

I rol(I t)
{
	I d = log(t) / log(10);
	I l = 0, r = t, p = p10(d);
	if (d > 1)
	{
		l = t % 10;
		r /= 10;
		r += (l * p);
	}

	R r;
}

I ror(I t)
{
	I d = log(t) / log(10);
	I l = 0, r = t, p = p10(d);
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
