//转置一个矩阵

#include <stdio.h>
int main()
{
	int a[3][4],i,j,k;
	for(i=0;i<=2;i++){
		for(j=0;j<=3;j++){
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
			}
	}
	printf("转置之前的矩阵：\n");
 for(i=0;i<=2;i++){
		for(j=0;j<=3;j++){
		 printf("%3d",a[i][j]);
		 }
		printf("\n");
	}
 for(i=0;i<=2;i++){
 	for(j=i;j<=3;j++){
 		k=a[i][j];
 		a[i][j]=a[j][i];
 		a[j][i]=k;
 		}
 	}
 	printf("转置之后的矩阵：\n");
 	for(i=0;i<=3;i++){
 		for(j=0;j<=2;j++)
 	   {
 	  	printf("%3d ",a[i][j]);
 	   }	
 	   printf("\n");
 	}
 	return 0;
}