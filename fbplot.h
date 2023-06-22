#ifndef _FBPLOT_H_
#define _FBPLOT_H_

#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

#define x_res	1280	//x resolution of display
#define y_res	799		//y resolution of display
#define col_n	4		//density of one pixel??? (r+g+b+blank=4)???

#define	WHITE	255, 255, 255
#define GRAY	127, 127, 127
#define	RED		255, 0, 0
#define	GREEN	0, 255, 0
#define	BLUE	0, 0, 255

unsigned char *fbmem0, *fbmem;
int fd;

void setup(){
	fd = open("/dev/fb0", O_RDWR);
	fbmem0 = mmap(NULL, x_res * y_res * col_n, PROT_WRITE, MAP_SHARED, fd, 0);
}

void plot(int x, int y, int r, int g, int b){
	fbmem=fbmem0;
	fbmem += x_res * col_n;
	fbmem[ (x + x_res * y) * col_n + 2 ] = r;
	fbmem[ (x + x_res * y) * col_n + 1 ] = g;
	fbmem[ (x + x_res * y) * col_n     ] = b;
}

void zplot(int x, int y, int z, int r, int g, int b){
	fbmem=fbmem0;
	fbmem += x_res * col_n;
	for(int j=0;j<z;j++){
		for(int i=0;i<z;i++){
			fbmem[ (x + x_res * y + i) * col_n + 2 ] = r;
			fbmem[ (x + x_res * y + i) * col_n + 1 ] = g;
			fbmem[ (x + x_res * y + i) * col_n     ] = b;
		}
		fbmem += x_res * col_n;
	}
}

void zplot_line(int x, int y, int h, int z, int r, int g, int b){
	fbmem=fbmem0;
	fbmem += x_res * col_n;
	for(int k=0;k<h;k++){
		for(int j=0;j<z;j++){
			for(int i=0;i<z;i++){
				fbmem[ (x + x_res * y + i) * col_n + 2 ] = r;
				fbmem[ (x + x_res * y + i) * col_n + 1 ] = g;
				fbmem[ (x + x_res * y + i) * col_n     ] = b;
			}
			fbmem += x_res * col_n;
		}
	}
	fbmem += x_res * col_n * z;
}

void setdown(){
	close(fd);
}

#endif
