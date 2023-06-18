#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

#define x_res 	1280
#define y_res 	800
#define col_n	4

int main(){
	int fd, x, y, x_size=255, y_size=255, x_off=0, y_off=0;
	unsigned char *fbmem;

	fd = open("/dev/fb0", O_RDWR);
	fbmem = mmap(NULL, x_res * y_res * col_n, PROT_WRITE, MAP_SHARED, fd, 0);

	fbmem += y_off * x_res * col_n + x_off * col_n;
	
	for(y = 0; y < y_size; y++){
		for(x = 0; x < x_size; x++){
			fbmem[x * col_n + 2 ] = 255; 	//R
			fbmem[x * col_n + 1 ] = y;		//G
			fbmem[x * col_n 	] = x;		//B
		}
		fbmem += x_res * col_n;
	}
	close(fd);
	return 0;
}
