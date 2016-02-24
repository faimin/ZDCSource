//void型
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	srand(time(NULL));
	for(int i=0;i<=5;i++){
		long m=rand();
		int n=m%10;
		printf("%d\n",n);
		}
	}
