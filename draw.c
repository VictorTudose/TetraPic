#include "set.c"

void draw_I(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,4,1,'I');
}

void draw_Ir(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,1,4,'I');
}

void draw_J(char image[1000][1000],int l,int c)
{
	set_image(image,l,c+1,3,1,'J');
	set_image(image,l,c,1,1,'J');
}

void draw_J1(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,1,3,'J');
	set_image(image,l+1,c,1,1,'J');
}

void draw_J2(char image[1000][1000],int l,int c)
{
	set_image(image,l+2,c+1,1,1,'J');
	set_image(image,l,c,3,1,'J');
}

void draw_J3(char image[1000][1000],int l,int c)
{
	set_image(image,l+1,c,1,3,'J');
	set_image(image,l,c+2,1,1,'J');
}

void draw_L(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,3,1,'L');
	set_image(image,l,c+1,1,1,'L');
}

void draw_L1(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,1,1,'L');
	set_image(image,l+1,c,1,3,'L');
}

void draw_L2(char image[1000][1000],int l,int c)
{
	set_image(image,l+2,c,1,2,'L');
	set_image(image,l,c+1,2,1,'L');
}

void draw_L3(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,1,3,'L');
	set_image(image,l+1,c+2,1,1,'L');
}


void draw_Z(char image[1000][1000],int l,int c)
{
	set_image(image,l,c+1,1,2,'Z');
	set_image(image,l+1,c,1,2,'Z');
}

void draw_Zr(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,2,1,'Z');
	set_image(image,l+1,c+1,2,1,'Z');
}


void draw_S(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,1,2,'S');
	set_image(image,l+1,c+1,1,2,'S');
}

void draw_Sr(char image[1000][1000],int l,int c)
{
	set_image(image,l,c+1,2,1,'S');
	set_image(image,l+1,c,2,1,'S');
}

void draw_O(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,2,2,'O');

}

void draw_T(char image[1000][1000],int l,int c)
{
	set_image(image,l+1,c,1,3,'T');
	set_image(image,l,c+1,1,1,'T');
}

void draw_T1(char image[1000][1000],int l,int c)
{
	set_image(image,l,c+1,3,1,'T');
	set_image(image,l+1,c,1,1,'T');
}

void draw_T2(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,1,3,'T');
	set_image(image,l+1,c+1,1,1,'T');
}

void draw_T3(char image[1000][1000],int l,int c)
{
	set_image(image,l,c,3,1,'T');
	set_image(image,l+1,c+1,1,1,'T');
}

void draw(char image[1000][1000],int l,int c,char type,int rot)
{
	switch(type)
	{
		case 'I':
		if(rot%2==1)
			draw_Ir(image,l,c);
		else
			draw_I(image,l,c);
		break;

		case 'O':
		draw_O(image,l,c);
		break;

		case 'S':
		if(rot%2==0)
			draw_S(image,l,c);
		else
			draw_Sr(image,l,c);
		break;

		case 'Z':
		if(rot%2==0)
			draw_Z(image,l,c);
		else
			draw_Zr(image,l,c);
		break;

		case 'L':
		if(rot==0)
			draw_L(image,l,c);
		if(rot==1)
			draw_L1(image,l,c);
		if(rot==2)
			draw_L2(image,l,c);
		if(rot==3)
			draw_L3(image,l,c);

		break;

		case 'J':
		if(rot==0)
			draw_J(image,l,c);
		if(rot==1)
			draw_J1(image,l,c);
		if(rot==2)
			draw_J2(image,l,c);
		if(rot==3)
			draw_J3(image,l,c);
		break;

		case 'T':
		if(rot==0)
			draw_T(image,l,c);
		if(rot==1)
			draw_T1(image,l,c);
		if(rot==2)
			draw_T2(image,l,c);
		if(rot==3)
			draw_T3(image,l,c);
		break;

		default:
		break;
	}
}