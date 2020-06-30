#include "bmp_header.h"

void color(pixel *p,char type)
{
	switch(type)
	{
		case 'I':
		p->R=0;
		p->G=0;
		p->B=255;
		break;

		case 'O':
		p->R=255;
		p->G=255;
		p->B=0;
		break;

		case 'S':
		p->R=255;
		p->G=0;
		p->B=0;
		break;

		case 'Z':
		p->R=0;
		p->G=255;
		p->B=0;
		break;

		case 'L':
		p->R=255;
		p->G=140;
		p->B=0;
		break;

		case 'J':
		p->R=255;
		p->G=0;
		p->B=255;
		break;

		case 'T':
		p->R=130;
		p->G=0;
		p->B=255;
		break;

		case 'W':
		p->R=255;
		p->G=255;
		p->B=255;
		break;

		case 'B':
		p->R=0;
		p->G=0;
		p->B=0;
		break;

		default:
		break;
	}
}

int Height(char type)
{

	switch(type)
	{
		case 'I':
		return 4;
		break;

		case 'O':
		case 'S':
		case 'Z':
		case 'T':
		return 2;
		break;

		case 'L':
		case 'J':
		return 3;
		break;

		default:
		return 0;
		break;

	}

}

int Width(char type)
{
	switch(type)
	{
		case 'S':
		case 'Z':
		case 'T':
		return 3;
		break;

		case 'L':
		case 'J':
		case 'O':
		return 2;
		break;

		case 'I':
		return 1;
		break;

		default:
		return 0;
		break;
	}
}

int equal3(unsigned char A1,unsigned char A2,unsigned char A3,unsigned char B1,unsigned char B2,unsigned char B3)
{
	if(A1 != B1)
		return 0;
	if(A2 != B2)
		return 0;
	if(A3 != B3)
		return 0;
	return 1;
}

char color_char(unsigned char R,unsigned char G,unsigned char B)
{
	if(equal3(R,G,B,0,0,0)) return 'B';
	if(equal3(R,G,B,0,0,255)) return 'I';
	if(equal3(R,G,B,255,255,0)) return 'O';
	if(equal3(R,G,B,255,0,0)) return 'S';
	if(equal3(R,G,B,0,255,0)) return 'Z';
	if(equal3(R,G,B,255,0,255)) return 'J';
	if(equal3(R,G,B,255,140,0)) return 'L';
	if(equal3(R,G,B,130,0,255)) return 'T';
	return 'W';
}