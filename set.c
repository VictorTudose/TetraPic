#include "dictionaries.c"

void set_filename(char file_name[30],char type,int rot)
{
	int i;

	for(i=strlen(file_name);i>=0;i--)
		file_name[i]='\0';

	strcat(file_name,"piesa_");
		file_name[strlen(file_name)]=type;

	if(rot==1)
		strcat(file_name,"_90");
	if(rot==2)
		strcat(file_name,"_180");
	if(rot==3)
		strcat(file_name,"_270");

	strcat(file_name,".bmp");

	file_name[strlen(file_name)]='\0';

}

void set_head(bmp_fileheader *head,unsigned int size)
{

	head->fileMarker1='B';
	head->fileMarker2='M';
	head->bfSize=size;
	head->unused1=0;
	head->unused2=0;
	head->imageDataOffset=54;

}

void set_infos(bmp_infoheader *infos,signed int height,signed int width, int size)
{

	infos->biSize=40;
	infos->planes=1;
	infos->bitPix=24;
	infos->biCompression=0;
	infos->biXPelsPerMeter=0;
	infos->biYPelsPerMeter=0;
	infos->biClrUsed=0;
	infos->biClrImportant=0;
	infos->height=height;
	infos->width=width;
	infos->biSizeImage=size;

}

void set_image(char image[1000][1000],int i0,int j0,int height,int width,char color)
{

	int i,j;
	for(i=i0;i<i0+height;i++)
		for(j=j0;j<j0+width;j++)
			image[i][j]=color;

}

void set_file(FILE *out,bmp_fileheader *head,bmp_infoheader *infos,int height,int width)
{
	int size,padd=0;

	if( (width*10)%4 != 0 )
		padd = 4 - (width*10)%4;

	size= 3*100*height*width + 10*height*padd;

	set_head(head,size+54);
	set_infos(infos,height*10,width*10,size);
	fwrite(head,sizeof(bmp_fileheader),1,out);
	fwrite(infos,sizeof(bmp_infoheader),1,out);

}