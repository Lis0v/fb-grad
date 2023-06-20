#include "fbplot.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define	x_mid	x_res/2
#define	NUM		38		//number of uhhhh idk columns idk

int main(){
	setup();
	
	srand(time(NULL));
	
	int x,y,rr,rg,rb;

	system("clear");

	while(1){
		rr=rand() % 255 + 0;
		rg=rand() % 255 + 0;
		rb=rand() % 255 + 0;
		
		for(int j=0;j<y_res/2;j++){
			for(int i=0;i<x_res;i++){
				x=i;
				y=y_res/2+sin(x/(x_res/NUM))*j;
				plot(x, y, rr, rg, rb);
			}
			usleep(600);
		}

		for(int j=y_res/2;j>0;j--){
			for(int i=0;i<x_res;i++){
				x=i;
				y=y_res/2+sin(x/(x_res/NUM))*j;
				plot(x, y, 0, 0, 0);
			}
			usleep(600);
		}
	}
	setdown();
}
