#include<stdio.h>
int Count(int A[],int n,int key){
	if(n<=0){
		return 0;
	}
	if(A[n-1]==key){
		return 1+Count(A,n-1,key);
	}
	else{
		return Count(A,n-1,key);
	}
}
int main(){
	int n,A[100],i,key;
	printf("Enter how many numbers:");
	scanf("%d",&n);
	printf("Enter the numbers:");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	printf("Enter the key number:");
	scanf("%d",&key);
	int j=Count(A,n,key);
	printf("The frequency of the number is:%d\n",j);
	return 0;
}