#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "write.c"
#include "free.c"
#include "search.c"

void Image(char image[1000][1000],int height,int width)
{
	int I,J;
	for(I=0;I<height;I++){
		for(J=0;J<width;J++)
			printf("%c", image[height-1-I][J]);
	printf("\n");
	}
	printf("\n");
}

int line(char image[1000][1000],int height,int width)
{
	int  i,j,ok;
	for(i=height-1;i>=0;i--)
	{
		ok=1;
		for(j=0;j<width;j++)
			if(strchr("BW",image[i][j]))
				ok=0;
		if(ok==1)
			return i;
	}
	return -1;
}

void remove_line(char image[1000][1000],int height,int width,int line)
{
	int i,j;
	for(i=line;i<height;i++)
		for(j=0;j<width;j++)
			image[i][j]=image[i+1][j];
}

int main(int argc,char *argv[])
{
	char types[7]="OISZLJT",
		 type,
		 file_name[30]="\0",
		 image[1000][1000];

	int height,
		width,
		aux,
		rot,
		col,
		L,
		row,
		game,
		N=0,
		i;

	char pieces[50];
	int rots[50],cols[50];


	FILE *out,*in,*file;

	bmp_fileheader H,*head=&H;
	bmp_infoheader I,*infos=&I;

	if(argv[1][0]=='1'||argv[1][0]=='2')
	for(i=0;i<7;i++){
		for(rot=0;rot<=3;rot++)
	{
		if(rot==0 && argv[1][0]=='2')
			rot=1;

		set_filename(file_name,types[i],rot);

		out=fopen(file_name,"wb");

		if(out == NULL){
			return -1;
		}

		height=Height(types[i])+2;
		width=Width(types[i])+2;

		if(rot%2==1)
		{
			aux=height;
			height=width;
			width=aux;
		}

		set_file(out,head,infos,height,width);

		set_image(image,0,0,height,width,'W');
		draw(image,1,1,types[i],rot);
		write_image(out,image,height,width);
		fclose(out);

		if(argv[1][0]=='1')
			rot=3;
	}
	}

	if(argv[1][0]=='3')
	{

		out=fopen("task3.bmp","wb");
		in=fopen("cerinta3.in","r");

		if(out == NULL){
			return -1;
		}	
		if(in == NULL){
			return -1;
		}

		fscanf(in,"%d",&N);
		fscanf(in,"%d",&height);
		fscanf(in,"%d",&width);

		set_image(image,0,0,height,width,'B');
		set_image(image,height,0,4,width,'W');

		game=1;
		while(N>0 && game)
		{
			fgetc(in);
			type=fgetc(in);
			fscanf(in,"%d",&rot);
			fscanf(in,"%d",&col);
			rot/=90;

			if(rot%2==0)
				row=height+4-Height(type);
			else
				row=height+4-Width(type);

			while(is_free(image,row,col,type,rot) && row )
				row--;
			
			draw(image,row,col,type,rot);

			if(row+Height(type) >= height && rot%2==0)
				game=0;
			if(row+Width(type) >= height && rot%2==1)
				game=0;

			if(game==1)
			{

				L=line(image,height,width);
				while(L!=-1)
				{
					remove_line(image,height,width,L);
					height--;
					set_image(image,height,0,1,width,'W');
					L=line(image,height,width);
				}

			}
			N--;
		}

		set_file(out,head,infos,height+4,width);
		write_image(out,image,height+4,width);

		fclose(out);
		fclose(in);

	}

	if(argv[1][0]=='4')
	{
		
		out=fopen("task4.bmp","wb");
		in=fopen("cerinta4.in","r");
		file=fopen("cerinta4.bmp","rb");
		
		if(out == NULL){
			return -1;
		}
		if(in == NULL){
			return -1;
		}
		if(file == NULL){
			return -1;
		}

		get_header(file,head);
		get_infos(file,infos);
		height=(infos->height)/10,
		width=(infos->width)/10;
		get_image(file,image,height,width);

		fscanf(in,"%d",&N);

		game=1;

		while(N>0 && game==1)
		{
			fgetc(in);
			type=fgetc(in);
			fscanf(in,"%d",&rot);
			fscanf(in,"%d",&col);
			rot/=90;
			
			if(rot%2==0)
				row=height-Height(type);
			else
				row=height-Width(type);

			while( is_free(image,row,col,type,rot) && row )
				row--;
			
			if(row+Height(type) >= height-3 && rot%2==0)
				game=0;
			if(row+Width(type) >= height-3 && rot%2==1)
				game=0;

			draw(image,row,col,type,rot);
			if(game==1)
			{

				L=line(image,height,width);
				while(L!=-1)
				{
					remove_line(image,height,width,L);
					height--;
					set_image(image,height,0,1,width,'W');
					L=line(image,height,width);
				}

			}
			N--;
		}

		set_file(out,head,infos,height,width);
		write_image(out,image,height,width);

		fclose(file);
		fclose(out);
		fclose(in);
	}

	if(argv[1][0]=='b')
	{
		file=fopen("bonus.bmp","rb");
		out=fopen("cerinta3.in","w");
		
		if(out == NULL){
			return -1;
		}
		if(file == NULL){
			return -1;
		}

		get_header(file,head);
		get_infos(file,infos);
		height=(infos->height)/10,
		width=(infos->width)/10;
		get_image(file,image,height,width);
		set_image(image,0,width,height,3,'B');

		for(row=height-4;row>=0;row--)
			for(col=width;col>=0;col--)
			{
				for(i=0;i<7;i++)
					for(rot=0;rot<=3;rot++)
						if(search(image,row,col,types[i],rot))
						{
							pieces[N]=types[i];
							rots[N]=90*rot;
							cols[N]=col;
							N++;
							undraw(image,row,col,types[i],rot);
						}

			}
		fprintf(out,"%d %d %d\n",N,height-4,width);
		N--;
		while(N>=0)
		{
			fprintf(out,"%c %d %d\n",pieces[N],rots[N],cols[N]);
			N--;
		}

		fclose(file);
		fclose(out);

	}

	return 0;

}