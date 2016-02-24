//利用递归遍历出一个数组中的元素

#include <stdio.h>
void k(int array[],int index){     //递归的是一个数组以及他的下标（最后一个元素的下标）
		printf("array[%d]=%d",index,array[index]);
		printf("\n");
		if(index>=1){
			k(array,index-1);    //为什么第二次调用的时候
	  }                              //array后面没有[]？？因为这里调用的
	 else return;              //是一整个数组，如果加括号的话是指的某一个元素
	}

int main(){
	int array[]={9,2,26,55,22,7,24,77,11,23,83,66,12};
	long len=sizeof(array)/sizeof(int);
	k(array,len-1);
	return 0;
	}