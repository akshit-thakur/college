#include<stdio.h>
int main(){
	int arr[10];
	int i,j;
	printf("Enter 10 numbers:\n");
	for(i=0;i<10;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<10;i++){
		for(j=i+1;j<10;j++){
			if(arr[j]<arr[i]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("After sorting in ascending order,the array is:\n");
	for(i=0;i<10;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
// 23/10/17
