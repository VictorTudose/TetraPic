int is_free_I(char image[1000][1000],int l,int c)
{
	if( !( strchr("BW",image[l-1][c]) ) )
		return 0;
	return 1;
}

int is_free_Ir(char image[1000][1000],int l,int c)
{
	if( !( strchr("BW",image[l-1][c]) ))
		return 0;
	if( !( strchr("BW",image[l-1][c+1])))
		return 0;
	if( !( strchr("BW",image[l-1][c+2])))
		return 0;
	if( !( strchr("BW",image[l-1][c+3])))
		return 0;
	return 1;
}

int is_free_J(char image[1000][1000],int l,int c)
{
	if( !( strchr("BW",image[l-1][c]) ) )
		return 0;
	if( !(strchr("BW",image[l-1][c+1]) ) )
		return 0;
	return 1;
}

int is_free_J1(char image[1000][1000],int l,int c)
{
	if(!strchr("BW",image[l-1][c]))
		return 0;
	if(!strchr("BW",image[l-1][c+1]))
		return 0;
	if(!strchr("BW",image[l-1][c+2]))
		return 0;
	return 1;
}

int is_free_J2(char image[1000][1000],int l,int c)
{
	if(!strchr("BW",image[l-1][c]))
		return 0;
	if(!strchr("BW",image[l+1][c+1]))
		return 0;
	return 1;
}

int is_free_J3(char image[1000][1000],int l,int c)
{
	if(!strchr("BW",image[l][c]))
		return 0;
	if(!strchr("BW",image[l][c+1]))
		return 0;
	if(!strchr("BW",image[l-1][c+2]))
		return 0;

	return 1;
}

int is_free_L(char image[1000][1000],int l,int c)
{
	if(!strchr("BW",image[l-1][c]))
		return 0;
	if(!strchr("BW",image[l-1][c+1]))
		return 0;
	return 1;
}

int is_free_L1(char image[1000][1000],int l,int c)
{		
	if(!strchr("BW",image[l-1][c]))
		return 0;
	if(!strchr("BW",image[l][c+1]))
		return 0;
	if(!strchr("BW",image[l][c+2]))
		return 0;
	return 1;
}

int is_free_L2(char image[1000][1000],int l,int c)
{
	if(!strchr("BW",image[l+1][c]))
		return 0;
	if(!strchr("BW",image[l-1][c+1]))
		return 0;
	return 1;
}

int is_free_L3(char image[1000][1000],int l,int c)
{
	if( !( strchr("BW",image[l-1][c]) ))
		return 0;
	if( !( strchr("BW",image[l-1][c+1])))
		return 0;
	if( !( strchr("BW",image[l-1][c+2])))
		return 0;
	return 1;
}

int is_free_Z(char image[1000][1000],int l,int c)
{
	if( !( strchr("BW",image[l][c]) ))
		return 0;
	if( !( strchr("BW",image[l-1][c+1])))
		return 0;
	if( !( strchr("BW",image[l-1][c+2])))
		return 0;
	return 1;
}

int is_free_Zr(char image[1000][1000],int l,int c)
{
	if( !( strchr("BW",image[l-1][c]) ))
		return 0;
	if( !( strchr("BW",image[l][c+1])))
		return 0;
	return 1;
}

int is_free_S(char image[1000][1000],int l,int c)
{
	if( !( strchr("BW",image[l-1][c]) ))
		return 0;
	if( !( strchr("BW",image[l-1][c+1])))
		return 0;
	if( !( strchr("BW",image[l][c+2])))
		return 0;
	return 1;
}

int is_free_Sr(char image[1000][1000],int l,int c)
{
	if( !( strchr("BW",image[l][c]) ))
		return 0;
	if( !( strchr("BW",image[l-1][c+1])))
		return 0;
	return 1;
}

int is_free_O(char image[1000][1000],int l,int c)
{
	if( !( strchr("BW",image[l-1][c]) ))
		return 0;
	if( !( strchr("BW",image[l-1][c+1])))
		return 0;
	return 1;
}

int is_free_T(char image[1000][1000],int l,int c)
{
	if( !( strchr("BW",image[l][c]) ))
		return 0;
	if( !( strchr("BW",image[l-1][c+1])))
		return 0;
	if( !( strchr("BW",image[l][c+2])))
		return 0;
	return 1;
}

int is_free_T1(char image[1000][1000],int l,int c)
{
	if( !( strchr("BW",image[l][c]) ))
		return 0;
	if( !( strchr("BW",image[l-1][c+1])))
		return 0;
	return 1;
}

int is_free_T2(char image[1000][1000],int l,int c)
{
	if( !( strchr("BW",image[l-1][c]) ))
		return 0;
	if( !( strchr("BW",image[l-1][c+1])))
		return 0;
	if( !( strchr("BW",image[l-1][c+2])))
		return 0;
	return 1;
}

int is_free_T3(char image[1000][1000],int l,int c)
{
	if( !( strchr("BW",image[l-1][c]) ))
		return 0;
	if( !( strchr("BW",image[l][c+1])))
		return 0;
	return 1;
}

int is_free(char image[1000][1000],int l ,int c,char type,int rot)
{
	switch(type)
	{
		case 'I':
		if(rot%2==1)
			return is_free_Ir(image,l,c);
		else
			return is_free_I(image,l,c);
		break;

		case 'O':
			return is_free_O(image,l,c);
		break;

		case 'S':
		if(rot%2==0)
			return is_free_S(image,l,c);
		else
			return is_free_Sr(image,l,c);
		break;

		case 'Z':
		if(rot%2==0)
			return is_free_Z(image,l,c);
		else
			return is_free_Zr(image,l,c);
		break;

		case 'L':
		if(rot==0)
			return is_free_L(image,l,c);
		if(rot==1)
			return is_free_L1(image,l,c);
		if(rot==2)
			return is_free_L2(image,l,c);
		if(rot==3)
			return is_free_L3(image,l,c);
		break;

		case 'J':
		if(rot==0)
			return is_free_J(image,l,c);
		if(rot==1)
			return is_free_J1(image,l,c);
		if(rot==2)
			return is_free_J2(image,l,c);
		if(rot==3)
			return is_free_J3(image,l,c);
		break;

		case 'T':
		if(rot==0)
			return is_free_T(image,l,c);
		if(rot==1)
			return is_free_T1(image,l,c);
		if(rot==2)
			return is_free_T2(image,l,c);
		if(rot==3)
			return is_free_T3(image,l,c);
		break;

		default:
		return 0;
		break;
	}
	return 0;
}