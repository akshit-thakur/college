#include<stdio.h>
void selsort(int*,int);
int main(){
	int arr[10]; int i;
	printf("Enter 10 numbers:\n");
	for(i=0;i<10;i++)
		scanf("%d",&arr[i]);
	selsort(arr,10);
	printf("After sorting in ascending order,the array is:\n");
	for(i=0;i<10;i++)
		printf("%d ",arr[i]);
	printf("\n");	
	return 0;
}
void selsort(int* arr,int size){
	int i,j;
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(arr[j]<arr[i]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
// 23/10/17
