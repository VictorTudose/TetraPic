#include "undraw.c"

void write_image(FILE *out,char image[1000][1000],signed int height,signed int width)
{
	int padd=0,
		i10,
		j10,
		i,
		j;
	int zero=0;
	pixel p;

	if( ((width*10) %4) != 0)
		padd = 4 - ((width*10) %4) ;


	for(i=0;i< height;i ++)
	{
		for(i10=0;i10<10;i10++)
		{
			
			for(j=0;j<width;j++)
			{
				color(&p,image[i][j]);
				for(j10=0;j10<10;j10++)
					fwrite(&p, sizeof(pixel) , 1 , out);
			}

			for(j=0;j<padd;j++)
				fwrite(&zero,sizeof(unsigned char), 1 , out );

		}
	}
}

void get_header(FILE *in,bmp_fileheader *head)
{
	fread( &head->fileMarker1, 1 , sizeof(unsigned char), in);
	fread( &head->fileMarker2, 1 , sizeof(unsigned char), in);
	fread( &head->bfSize, 1 , sizeof(unsigned int), in);
	fread( &head->unused1, 1 , sizeof(unsigned short), in);
	fread( &head->unused2, 1 , sizeof(unsigned short), in);
	fread( &head->imageDataOffset, 1 , sizeof(unsigned int), in);
}

void get_infos(FILE *in, bmp_infoheader *infos)
{
	fread( &infos->biSize, 1 , sizeof(unsigned int), in);
	fread( &infos->width, 1 , sizeof(signed int), in);
	fread( &infos->height, 1 , sizeof(signed int), in);
	fread( &infos->planes, 1 , sizeof(unsigned short), in);
	fread( &infos->bitPix, 1 , sizeof(unsigned short), in);
	fread( &infos->biCompression, 1 , sizeof(unsigned int), in);
	fread( &infos->biSizeImage, 1 , sizeof(unsigned int), in);
	fread( &infos->biXPelsPerMeter, 1 , sizeof(int), in);
	fread( &infos->biYPelsPerMeter, 1 , sizeof(int), in);
	fread( &infos->biClrUsed, 1 , sizeof(unsigned int), in);
	fread( &infos->biClrImportant, 1 , sizeof(unsigned int), in);

}

void get_image(FILE *in,char image[1000][1000],int height,int width)
{
	int i,j,padd=0,i9,j9;
	unsigned char zero;

	if( ((width*10) %4) != 0)
		padd = 4 - ((width*10) %4) ;

	unsigned char R,G,B;

	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{

			fread( &B , sizeof(unsigned char) , 1 , in);
			fread( &G , sizeof(unsigned char) , 1 , in);
			fread( &R , sizeof(unsigned char) , 1 , in);

		
			image[i][j]=color_char(R,G,B);

			
			for(j9=0;j9<9;j9++)
				{
			fread( &B , sizeof(unsigned char) , 1 , in);
			fread( &G , sizeof(unsigned char) , 1 , in);
			fread( &R , sizeof(unsigned char) , 1 , in);
		
				}
		}

		for(j=0;j<padd;j++)
			{
				fread( &zero , sizeof(unsigned char), 1 , in );
			}

		for(i9=0;i9<9;i9++)
		{
			for(j=0;j<width;j++)
			{
				{
			fread( &B , sizeof(unsigned char) , 1 , in);
			fread( &G , sizeof(unsigned char) , 1 , in);
			fread( &R , sizeof(unsigned char) , 1 , in);
			
				}
				for(j9=0;j9<9;j9++)
				{
			fread( &B , sizeof(unsigned char) , 1 , in);
			fread( &G , sizeof(unsigned char) , 1 , in);
			fread( &R , sizeof(unsigned char) , 1 , in);
				}
			}

			for(j=0;j<padd;j++){
				fread( &zero , sizeof(unsigned char), 1 , in );
			}
			
		}

	}
	
}
