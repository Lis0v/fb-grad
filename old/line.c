#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

#define x_res 	1280
#define y_res 	800
#define x_off	100
#define y_off 	100
#define col_n	4

int main(){
	int fd, x, y, x_size=50, y_size=50;
	unsigned char *fbmem;

	fd = open("/dev/fb0", O_RDWR);
	fbmem = mmap(NULL, x_res * y_res * col_n, PROT_WRITE, MAP_SHARED, fd, 0);

	fbmem += y_off * x_res * col_n + x_off * col_n;
	
	for(x = 0; x < x_size; x++){
		fbmem[(x + x_res * y) * col_n + 0] = 255; 	//R
		fbmem[(x + x_res * y) * col_n + 1] = 255;	//G
		fbmem[(x + x_res * y) * col_n + 2] = 255;	//B
		y++;
	}
	
	fbmem += x_res * col_n;
	
	close(fd);
	return 0;
}
