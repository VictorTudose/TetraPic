int search_I(char image[1000][1000],int l,int c)
{
	if(image[l][c]!='I')
		return 0;
	if(image[l+1][c]!='I')
		return 0;
	if(image[l+2][c]!='I')
		return 0;
	if(image[l+3][c]!='I')
		return 0;
	return 1;
}

int search_Ir(char image[1000][1000],int l,int c)
{
	if(image[l][c]!='I')
		return 0;
	if(image[l][c+1]!='I')
		return 0;
	if(image[l][c+2]!='I')
		return 0;
	if(image[l][c+3]!='I')
		return 0;
	return 1;
}

int search_J(char image[1000][1000],int l,int c)
{
	if(image[l][c]!='J')
		return 0;
	if(image[l][c+1]!='J')
		return 0;
	if(image[l+1][c+1]!='J')
		return 0;
	if(image[l+2][c+1]!='J')
		return 0;
	return 1;
}

int search_J1(char image[1000][1000],int l,int c)
{
	if(image[l][c]!='J')
		return 0;
	if(image[l][c+1]!='J')
		return 0;
	if(image[l][c+2]!='J')
		return 0;
	if(image[l+1][c]!='J')
		return 0;
	return 1;
}

int search_J2(char image[1000][1000],int l,int c)
{
	if(image[l][c]!='J')
		return 0;
	if(image[l+1][c]!='J')
		return 0;
	if(image[l+2][c]!='J')
		return 0;
	if(image[l+2][c+1]!='J')
		return 0;
	return 1;
}

int search_J3(char image[1000][1000],int l,int c)
{
	if(image[l+1][c]!='J')
		return 0;
	if(image[l+1][c+1]!='J')
		return 0;
	if(image[l+1][c+2]!='J')
		return 0;
	if(image[l][c+2]!='J')
		return 0;
	return 1;
}

int search_L(char image[1000][1000],int l,int c)
{
	if(image[l][c]!='L')
		return 0;
	if(image[l+1][c]!='L')
		return 0;
	if(image[l+2][c]!='L')
		return 0;
	if(image[l][c+1]!='L')
		return 0;
	return 1;
}

int search_L1(char image[1000][1000],int l,int c)
{
	
	if(image[l][c]!='L')
		return 0;
	if(image[l+1][c]!='L')
		return 0;
	if(image[l+1][c+1]!='L')
		return 0;
	if(image[l+1][c+2]!='L')
		return 0;
	
	return 1;
}

int search_L2(char image[1000][1000],int l,int c)
{
	if(image[l][c+2]!='L')
		return 0;
	if(image[l+1][c]!='L')
		return 0;
	if(image[l+1][c+1]!='L')
		return 0;
	if(image[l+1][c+2]!='L')
		return 0;
	
	return 1;
}

int search_L3(char image[1000][1000],int l,int c)
{
	if(image[l][c]!='L')
		return 0;
	if(image[l][c+1]!='L')
		return 0;
	if(image[l][c+2]!='L')
		return 0;
	if(image[l+1][c+2]!='L')
		return 0;
	return 1;
}


int search_Z(char image[1000][1000],int l,int c)
{
	if(image[l+1][c]!='Z')
		return 0;
	if(image[l+1][c+1]!='Z')
		return 0;
	if(image[l][c+1]!='Z')
		return 0;
	if(image[l][c+2]!='Z')
		return 0;
	return 1;
}

int search_Zr(char image[1000][1000],int l,int c)
{
	if(image[l][c]!='Z')
		return 0;
	if(image[l+1][c+1]!='Z')
		return 0;
	if(image[l+1][c]!='Z')
		return 0;
	if(image[l+2][c+1]!='Z')
		return 0;
	return 1;
}


int search_S(char image[1000][1000],int l,int c)
{
	if(image[l][c]!='S')
		return 0;
	if(image[l+1][c+1]!='S')
		return 0;
	if(image[l][c+1]!='S')
		return 0;
	if(image[l+1][c+2]!='S')
		return 0;
	return 1;
}

int search_Sr(char image[1000][1000],int l,int c)
{
	if(image[l+1][c]!='S')
		return 0;
	if(image[l+2][c]!='S')
		return 0;
	if(image[l][c+1]!='S')
		return 0;
	if(image[l+1][c+1]!='S')
		return 0;
	return 1;
}

int search_O(char image[1000][1000],int l,int c)
{
	if(image[l+1][c]!='O')
		return 0;
	if(image[l+1][c]!='O')
		return 0;
	if(image[l][c+1]!='O')
		return 0;
	if(image[l+1][c+1]!='O')
		return 0;
	return 1;
}

int search_T(char image[1000][1000],int l,int c)
{
	if(image[l][c+1]!='T')
		return 0;
	if(image[l+1][c]!='T')
		return 0;
	if(image[l+1][c+1]!='T')
		return 0;
	if(image[l+1][c+2]!='T')
		return 0;
	return 1;
}

int search_T1(char image[1000][1000],int l,int c)
{
	if(image[l][c+1]!='T')
		return 0;
	if(image[l][c+1]!='T')
		return 0;
	if(image[l+1][c+1]!='T')
		return 0;
	if(image[l+2][c+1]!='T')
		return 0;
	return 1;
}

int search_T2(char image[1000][1000],int l,int c)
{

	if(image[l][c]!='T')
		return 0;
	if(image[l][c+1]!='T')
		return 0;
	if(image[l][c+2]!='T')
		return 0;
	if(image[l+1][c+1]!='T')
		return 0;
	return 1;
}

int search_T3(char image[1000][1000],int l,int c)
{
	if(image[l][c]!='T')
		return 0;
	if(image[l][c+1]!='T')
		return 0;
	if(image[l][c+2]!='T')
		return 0;
	if(image[l+1][c+1]!='T')
		return 0;
	return 1;
}

int search(char image[1000][1000],int l,int c,char type,int rot)
{
	switch(type)
	{
		case 'I':
		if(rot%2==1)
			return search_Ir(image,l,c);
		else
			return search_I(image,l,c);
		break;

		case 'O':
		return search_O(image,l,c);
		break;

		case 'S':
		if(rot%2==0)
			return search_S(image,l,c);
		else
			return search_Sr(image,l,c);
		break;

		case 'Z':
		if(rot%2==0)
			return search_Z(image,l,c);
		else
			return search_Zr(image,l,c);
		break;

		case 'L':
		if(rot==0)
			return search_L(image,l,c);
		if(rot==1)
			return search_L1(image,l,c);
		if(rot==2)
			return search_L2(image,l,c);
		if(rot==3)
			return search_L3(image,l,c);
		break;

		case 'J':
		if(rot==0)
			return search_J(image,l,c);
		if(rot==1)
			return search_J1(image,l,c);
		if(rot==2)
			return search_J2(image,l,c);
		if(rot==3)
			return search_J3(image,l,c);
		break;

		case 'T':
		if(rot==0)
			return search_T(image,l,c);
		if(rot==1)
			return search_T1(image,l,c);
		if(rot==2)
			return search_T2(image,l,c);
		if(rot==3)
			return search_T3(image,l,c);
		break;

		default:
		return 0;
		break;
	}
	return 0;
}