#include <stdio.h>
void s99(){	
	for(int i=1;i<=9;i++){
		for(int j=1;j<=i;j++){
			printf("%d*%d=%-2d  ",j,i,j*i);
			}		
		printf("\n");	
		}
	}
int main(){
	s99();
	return 0;
	}