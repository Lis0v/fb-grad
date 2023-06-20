#include "fbplot.h"
#include <math.h>
#include <stdio.h>

#define x_mid x_res/2

int main(){
	setup();
	
	int x,y;
	while(1){
		for(int j=0;j<y_res/2;j++){
			for(int i=0;i<x_res;i++){
				x=i;
				y=y_res/2+sin(x*10)*j;
				plot(x, y, 0, j, 255);
			}
			usleep(600);
		}
		system("clear");
		for(int j=y_res/2;j>0;j--){
			for(int i=0;i<x_res;i++){
				x=i;
				y=y_res/2+sin(x*10)*j;
				plot(x, y, 255, j, 0);
			}
			usleep(600);
		}
		system("clear");
	}
	setdown();
}
