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

L r4(L s)
{
    L r=444+(s%77777777), or=r, p=1;
    I d = log(r) / log(10);
    I l=0,i=d;
    I *dd;
    
    dd=calloc(d+1,sizeof(dd));
    
    for(;d>=0;i--,d--,r/=10)
    {
        l=r%10;
        if((l<4)||(l>7)) l=4+(l%8);
        dd[i]=l;
    }
    for(i=log(or) / log(10);i>=0;i--,p*=10)
    {
        r+=dd[i]*p;
    }
    return r;
}

V rnd(I t)
{
    if(t==1)
    {
        for(int j=1;j<747;j++) { A[j]=(C)32+((clock()%100+A[j-1])%100); }
    }
    else if (t==4)
    {
        M[0]=r4(clock());
        for(int j=1;j<65536;j++) { M[j]=r4(clock()+M[j-1]); }
    }
    else
    {
        for(int j=1;j<747;j++) { B[j]=(S)444+((clock()%300+A[j-1])%300); }
    }
}

V rd(V)
{
    
}

V dmp(int t)
{
    if(t==4)
    {
        for(int i=0;i<65536;i++) Od(M[i]);
    }
}

I main(I n, C **a)
{
	M = calloc(65536, sizeof(M));
    A = (C*)malloc(747);
    B = (S*)malloc(128);
    
    rnd(1); rnd(0); rnd(4);
    
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
    
    B['A']=654;B['B']=444;B['C']=476;
    B['D']=655;B['E']=445;B['F']=477;
    B['G']=656;B['H']=446;B['I']=544;
    B['J']=657;B['K']=447;B['L']=545;
    B['M']=664;B['N']=454;B['O']=546;
    B['P']=665;B['Q']=455;B['R']=547;
    B['S']=666;B['T']=456;B['U']=554;
    B['V']=667;B['X']=457;B['Y']=555;
    B['W']=674;B['Z']=464;B['!']=556;
    B['?']=675;B['.']=465;B[',']=557;
    B['$']=676;B['%']=466;B['/']=564;
    B['*']=677;B['(']=467;B[')']=565;
    B[':']=744;B[';']=474;B['[']=566;
    B[']']=745;B['{']=475;B['}']=567;
    
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
