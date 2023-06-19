#include "fbplot.h"

int main(){
	setup();
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			plot(i, j, WHITE);
		}
	}
	setdown();
}
