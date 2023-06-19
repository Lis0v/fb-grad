#ifndef _FBPLOT_H_
#define _FBPLOT_H_

#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

#define x_res	1280
#define y_res	800
#define col_n	4

#define WHITE	255, 255, 255
#define RED		255, 0, 0
#define GREEN	0, 255, 0
#define BLUE	0, 0, 255

unsigned char *fbmem0, *fbmem;
int fd;

void setup(){
	fd = open("/dev/fb0", O_RDWR);
	fbmem0 = mmap(NULL, x_res * y_res * col_n, PROT_WRITE, MAP_SHARED, fd, 0);
}

void plot(int x, int y, int r, int g, int b){
	fbmem=fbmem0;
	for(int i=0;i<y;i++){
		fbmem += x_res * col_n;
		fbmem[ x * col_n + 2 ] = r;
		fbmem[ x * col_n + 1 ] = g;
		fbmem[ x * col_n     ] = b;
	}
}

void setdown(){
	close(fd);
}

#endif
