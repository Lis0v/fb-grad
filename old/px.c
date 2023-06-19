#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

#define x_res 	1280
#define y_res 	800
#define x_off	100
#define y_off	100
#define col_n	4

int main(){
	int fd, x=1, y=1;
	unsigned char *fbmem;

	fd = open("/dev/fb0", O_RDWR);
	fbmem = mmap(NULL, x_res * y_res * col_n, PROT_WRITE, MAP_SHARED, fd, 0);

	fbmem += y_off * x_res * col_n + x_off * col_n;
	
	fbmem[x * col_n + 2 ] = 255;	//R
	fbmem[x * col_n + 1 ] = 255;	//G
	fbmem[x * col_n 	] = 255;	//B

	close(fd);
	return 0;
}
