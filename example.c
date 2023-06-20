#include "fbplot.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define x_mid x_res/2

int main(){
	setup();
	
	int x,y;
	
	for(int i =1;i<100;i++){
		x=i;
		y=x;
		plot(x, y, WHITE);
	}
	setdown();
}
