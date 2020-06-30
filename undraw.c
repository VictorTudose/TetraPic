#include "draw.c"

void undraw_I(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,4,1,'B');
}

void undraw_Ir(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,1,4,'B');
}

void undraw_J(char image[1000][1000],int l,int c)
{
	set_image(image,l,c+1,3,1,'B');
	set_image(image,l,c,1,1,'B');
}

void undraw_J1(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,1,3,'B');
	set_image(image,l+1,c,1,1,'B');
}

void undraw_J2(char image[1000][1000],int l,int c)
{
	set_image(image,l+2,c+1,1,1,'B');
	set_image(image,l,c,3,1,'B');
}

void undraw_J3(char image[1000][1000],int l,int c)
{
	set_image(image,l+1,c,1,3,'B');
	set_image(image,l,c+2,1,1,'B');
}

void undraw_L(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,3,1,'B');
	set_image(image,l,c+1,1,1,'B');
}

void undraw_L1(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,1,1,'B');
	set_image(image,l+1,c,1,3,'B');
}

void undraw_L2(char image[1000][1000],int l,int c)
{
	set_image(image,l+2,c,1,2,'B');
	set_image(image,l,c+1,2,1,'B');
}

void undraw_L3(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,1,3,'B');
	set_image(image,l+1,c+2,1,1,'B');
}


void undraw_Z(char image[1000][1000],int l,int c)
{
	set_image(image,l,c+1,1,2,'B');
	set_image(image,l+1,c,1,2,'B');
}

void undraw_Zr(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,2,1,'B');
	set_image(image,l+1,c+1,2,1,'B');
}


void undraw_S(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,1,2,'B');
	set_image(image,l+1,c+1,1,2,'B');
}

void undraw_Sr(char image[1000][1000],int l,int c)
{
	set_image(image,l,c+1,2,1,'B');
	set_image(image,l+1,c,2,1,'B');
}

void undraw_O(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,2,2,'B');

}

void undraw_T(char image[1000][1000],int l,int c)
{
	set_image(image,l+1,c,1,3,'B');
	set_image(image,l,c+1,1,1,'B');
}

void undraw_T1(char image[1000][1000],int l,int c)
{
	set_image(image,l,c+1,3,1,'B');
	set_image(image,l+1,c,1,1,'B');
}

void undraw_T2(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,1,3,'B');
	set_image(image,l+1,c+1,1,1,'B');
}

void undraw_T3(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,3,1,'B');
	set_image(image,l+1,c+1,1,1,'B');
}

void undraw(char image[1000][1000],int l,int c,char type,int rot)
{
	switch(type)
	{
		case 'I':
		if(rot%2==1)
			undraw_Ir(image,l,c);
		else
			undraw_I(image,l,c);
		break;

		case 'O':
		undraw_O(image,l,c);
		break;

		case 'S':
		if(rot%2==0)
			undraw_S(image,l,c);
		else
			undraw_Sr(image,l,c);
		break;

		case 'Z':
		if(rot%2==0)
			undraw_Z(image,l,c);
		else
			undraw_Zr(image,l,c);
		break;

		case 'L':
		if(rot==0)
			undraw_L(image,l,c);
		if(rot==1)
			undraw_L1(image,l,c);
		if(rot==2)
			undraw_L2(image,l,c);
		if(rot==3)
			undraw_L3(image,l,c);

		break;

		case 'J':
		if(rot==0)
			undraw_J(image,l,c);
		if(rot==1)
			undraw_J1(image,l,c);
		if(rot==2)
			undraw_J2(image,l,c);
		if(rot==3)
			undraw_J3(image,l,c);
		break;

		case 'T':
		if(rot==0)
			undraw_T(image,l,c);
		if(rot==1)
			undraw_T1(image,l,c);
		if(rot==2)
			undraw_T2(image,l,c);
		if(rot==3)
			undraw_T3(image,l,c);
		break;

		default:
		break;
	}
}