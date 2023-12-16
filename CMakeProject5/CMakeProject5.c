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
	I d = (I) log(t) / log(10);
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
	I d = (I) log(t) / log(10);
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

L n2(L s)
/* half-normalise to I4 */
{
    L r=s, or=r, p=1;
    I d = log(r) / log(10);
    I l=0,i=d;
    I *dd;
    
    dd=calloc(d+1,sizeof(dd));
    
    for(;d>=0;i--,d--,r/=10)
    {
        l=r%10;
        if(l<4) l=4+(l%8);
        dd[i]=l;
    }
    r=0;
    i = log(or)/log(10);
    for(;i>=0;i--,p*=10)
    {
        r+=dd[i]*p;
    }
    return r;
}

L n4(L s)
/* normalise to I4 */
{
    L r=s, or=r, p=1;
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
    r=0;
    i = log(or)/log(10);
    for(;i>=0;i--,p*=10)
    {
        r+=dd[i]*p;
    }
    return r;
}

L r4(L s)
{
    srand((unsigned int)s);
    L r=444+(s%77777777)+rand(), or=r, p=1;
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
    i = log(or) / log(10);
    for(;i>=0;i--,p*=10)
    {
        r+=dd[i]*p;
    }
    return r;
}

V rnd(I t)
{
    if(t==1)
    {
        for(int j=1;j<778;j++) { A[j]=(C)32+((time(NULL)%100+A[j-1])%100); }
    }
    else if (t==4)
    {
        M[0]=r4(time(NULL));
        for(int j=1;j<65536;j++) { M[j]=r4(time(NULL)+M[j-1]); }
    }
    else
    {
        for(int j=1;j<128;j++) { B[j]=(S)444+((time(NULL)%300+A[j-1])%300); }
    }
}

L getn(FILE*f)
{
    /* numbers are written in little-endian format */
    wchar_t c;
    L r=0;
    L p=1;
    while((c=fgetwc(f))!='\n')
    {
        r+=(c-'0')*p;
        p*=10;
    }
    return r;
}

V rdiv4(C c)
{
    switch(c)
    {
        case '!':
            *R0/=4;
            *R0=n4(*R0);
            break;
        case '@':
            *R1/=4;
            *R1=n4(*R1);
            break;
        case '#':
            *R2/=4;
            *R2=n4(*R2);
            break;
        case '$':
            *R3/=4;
            *R3=n4(*R3);
            break;
	case '%':
	    *R0/=4;
	    break;
	case '^':
	    *R1/=4;
	    break;
	case '&':
	    *R2/=4;
	    break;
	case '*':
	    *R3/=4;
	    break;
	case '(':
	    *R0/=4;
	    *R0=n2(*R0);
	    break;
	case ')':
	    *R1/=4;
	    *R1=n2(*R1);
	    break;
	case '_':
	    *R2/=4;
	    *R2=n2(*R2);
	    break;
	case '+':
	    *R3/=4;
	    *R3=n2(*R3);
	    break;
	default:
	    break;
    }
}

V rd(FILE*f)
{
    I PC=0;
    wchar_t c;
#define M(x) M[PC]=x
#define BR PC++;break
    while((c=fgetwc(f))!=EOF)
    {
        switch(c)
        {
            case '0':
                M(0);
                BR;
            case '1':
                M(t2d(1));
                BR;
            case '2':
                M(t2d(2));
                BR;
            case '3':
                M(t2d(3));
                BR;
            case '~':
                M(r4(M[PC]));
                BR;
            case '!':
                *R0=getn(f);
                break;
            case '@':
                *R1=getn(f);
                break;
            case '#':
                *R2=getn(f);
                break;
            case '$':
                *R3=getn(f);
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'Y':
            case 'X':
            case 'W':
            case 'Z':
            case '%':
            case '*':
            case '(':
            case ')':
            case ':':
            case ';':
            case '[':
            case ']':
            case '?':
                M(B[c]);
                BR;
            case '|':
                M(B['/']);
                BR;
            case L'¡':
                M(B['!']);
                BR;
            case L'…':
                M(B['.']);
                BR;
            case L'∞':
                M(B[',']);
                BR;
            case L'¢':
                M(B['$']);
                BR;
            case L'•':
                M(B['{']);
                BR;
            case L'·':
                M(B['}']);
                BR;
            case L'ø':
                M(B[' ']);
                BR;
            case L'®':
                M(B['\n']);
                BR;
            case L'†':
                M(B['\t']);
                BR;
            case '/':
                c=fgetwc(f);
                switch(c)
                {
                    case '!':
                    case '@':
                    case '#':
                    case '$':
		    case '%':
		    case '^':
		    case '&':
		    case '*':
	            case '(':
		    case ')':
		    case '_':
		    case '+':
                        rdiv4(c);
                        break;
                    default:
                        ungetc(c,f);
                        PC=t2d(getn(f));
                        break;
                }
                break;
            case '.':
                c=fgetwc(f);
                switch(c)
                {
                    case '!':
                        Od(*R0);
                        break;
                    case '@':
                        Od(*R1);
                        break;
                    case '#':
                        Od(*R2);
                        break;
                    case '$':
                        Od(*R3);
                        break;
                    default:
                        ungetc(c,f);
                        Od(M[t2d(getn(f))]);
                        break;
                }
                break;
            case ',':
                Oc(M[PC]);
                BR;
	    case '}':
		M(ror(M[PC]));
		BR;
	    case '{':
		M(rol(M[PC]));
		BR;
            case '+':
		c=fgetwc(f);
		switch(c)
		{
		     case '!':
			*R0+=M[PC];
			*R0=n4(*R0);
			BR;
		     case '@':
			*R1+=M[PC];
			*R1=n4(*R1);
			BR;
		     case '#':
			*R2+=M[PC];
			*R2=n4(*R2);
			BR;
		     case '$':
			*R3+=M[PC];
			*R3=n4(*R3);
			BR;
		     default:
			break;
		}
		break;
	    case '-':
		c=fgetwc(f);
		switch(c)
		{
		     case '!':
			*R0-=M[PC];
			*R0=n4(*R0);
			BR;
		     case '@':
			*R1-=M[PC];
			*R1=n4(*R1);
			BR;
		     case '#':
			*R2-=M[PC];
			*R2=n4(*R2);
			BR;
		     case '$':
			*R3-=M[PC];
			*R3=n4(*R3);
			BR;
		     default:
			break;
		}
		break;
	    case '>':
		c=fgetwc(f);
		switch(c)
		{
		    case '!':
		    	*R0+=5;
			break;
		    case '@':
			*R1+=5;
			break;
		    case '#':
			*R2+=5;
			break;
		    case '$':
			*R3+=5;
			break;
		    default:
			ungetc(c,f);
			M[getn(f)]=*R3;
			BR;
		}
		break;
	    case '<':
		c=fgetwc(f);
		switch(c)
		{
		    case '!':
		    	*R0-=5;
			break;
		    case '@':
			*R1-=5;
			break;
		    case '#':
			*R2-=5;
			break;
		    case '$':
			*R3-=5;
			break;
		    default:
			ungetc(c,f);
			*R3=M[getn(f)];
			BR;
		}
		break;
	    case '\\':
		c=fgetwc(f);
		switch(c)
		{
		    case '!':
		    	t=*R0;
			*R0=*R1;
			*R1=t;
			break;
		    case '@':
			t=*R1;
			*R1=*R2;
			*R2=t;
			break;
		    case '#':
			t=*R2;
			*R2=*R3;
			*R3=t;
			break;
		    case '$':
			t=*R3;
			*R3=*R0;
			*R0=t;
			break;
		}
		break;
            case '`':
                R;
            case '\n':
            case ' ':
                break;
            default:
                break;
        }
    }
}

V dmp(int t)
{
    O("\n");
    switch(t)
    {
        case 4:
            for(int i=0;i<128;i++) Od(M[i]);
            break;
        case 3:
            O("R0: %ld\t[%ld]\n",*R0,t2d(*R0));
            O("R1: %ld\t[%ld]\n",*R1,t2d(*R1));
            O("R2: %ld\t[%ld]\n",*R2,t2d(*R2));
            O("R3: %ld\t[%ld]\n",*R3,t2d(*R3));
            break;
        default:
            break;
    }
}

V i0(V)
{
    M = calloc(65536,sizeof(M));
    A = calloc(778,sizeof(A));
    B = calloc(128,sizeof(B));
    if (!A)EXIT;
    if (!B)EXIT;
    if (!M)EXIT;
    R0 = calloc(1,sizeof(R0));
    R1 = calloc(1,sizeof(R0));
    R2 = calloc(1,sizeof(R0));
    R3 = calloc(1,sizeof(R0));
    if (!R0)EXIT;
    if (!R1)EXIT;
    if (!R2)EXIT;
    if (!R3)EXIT;
    
    setlocale(LC_ALL,"");
    
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
    A[777]=' ';A[776]='\n';A[775]='\t';
    
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
    B[' ']=777;
    B['\n']=776;B[L'\t']=775;
}

I main(I n, C **a)
{
    FILE*fi;
    
    i0();
    
    
    
    
    
    if(n>1) {fi=fopen(a[1],"r+");if(fi)rd(fi);fclose(fi);}
    
    //dmp(4);
    //dmp(3);
    
    O("```````\n");
    
	R 0;
}
