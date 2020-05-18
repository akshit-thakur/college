#include<stdio.h>
#include<string.h>

int main(){
	int r,i,j; //r is the roll number to search
	char n[20]; //n is the name to search
	
	struct student{
		int rno;
		char name[20];
		int m1,m2,total;
		float avg;
	}stu[3],temp; //temp to swap values
	
	for(i=0;i<3;i++){ //filling the structure
		printf("Enter roll number: ");
		scanf("%d",stu[i].rno);
		fflush(stdin);
		printf("Enter name: ");
		gets(stu[i].name);
		printf("Enter marks of 2 subjects: ");
		scanf("%d%d",&stu[i].m1,&stu[i].m2);
		stu[i].total=stu[i].m1+stu[i].m2;
		stu[i].avg=(float)stu[i].total/2;
	}
	
	printf("\nRoll no.\tName\tMarks 1\tMarks 2\tTotal\tAverage\n");
	for(i=0;i<3;i++)
		printf("%d\t\t%s\t%d\t%d\t%d\t%f\n",stu[i].rno,stu[i].name,stu[i].m1,stu[i].m2,stu[i].total,stu[i].avg);
	
	
	printf("Sorting by name:\n\n"); //Sorting the structure by name
	for(i=0;i<3;i++){
		for(j=i+1;j<3;j++){
			if((strcmp(stu[i].name,stu[j].name))>0){
				temp=stu[i];
				stu[i]=stu[j];
				stu[j]=temp;
			}
		}
	}
	
	printf("\nRoll no.\tName\tMarks 1\tMarks 2\tTotal\tAverage\n");
	for(i=0;i<3;i++)
		printf("%d\t\t%s\t%d\t%d\t%d\t%f\n",stu[i].rno,stu[i].name,stu[i].m1,stu[i].m2,stu[i].total,stu[i].avg);
		
	printf("\nEnter the roll number you want to search:\n");
	scanf("%d",&r);
	
	for(i=0;i<3;i++){
		if(stu[i].rno==r){
			printf("Found! Here are the details:\n");
			printf("\nRoll no. %d\nName %s\nMarks 1 %d \nMarks 2 %d\nTotal %d\nAverage %f\n",stu[i].rno,stu[i].name,stu[i].m1,stu[i].m2,stu[i].total,stu[i].avg);
			break;
		}
	}
	
	if(i==4)
		printf("Not found!\n");
	printf("\nEnter the name you want to search:\n");
	
	fflush(stdin);
	
	gets(n);
	
	for(i=0;i<3;i++){
		if((strcmp(stu[i].name,n))==0){
			printf("Found! Here are the details:\n");
			printf("\nRoll no. %d\nName %s\nMarks 1 %d \nMarks 2 %d\nTotal %d\nAverage %f\n",stu[i].rno,stu[i].name,stu[i].m1,stu[i].m2,stu[i].total,stu[i].avg);
			break;
		}
	}
	if(i==4)
		printf("Not found!\n");
	return 0;
}
