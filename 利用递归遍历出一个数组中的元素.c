//利用递归遍历出一个数组中的元素

#include <stdio.h>
void k(int array[],int index){     //递归的是一个数组以及他的下标（最后一个元素的下标）
		printf("array[%d]=%d",index,array[index]);
		printf("\n");
		if(index>=1){
			k(array,index-1);    //为什么第二次调用的时候array后面没有[]？？？
	  }                              //因为这个数组现在已经是已知的了，array就代表这个已经数组。在一开始定义时由于数组未知，所以要添加[]。
	 else return;
	}

int main(){
	int array[]={9,2,26,55,22,7,24,77,11,23,83,66,12};
	long len=sizeof(array)/sizeof(int);
	k(array,len-1);    //-1是因为sizeof计算出的数组长度里包含/0这个元素，所以得减掉
	return 0;
	}