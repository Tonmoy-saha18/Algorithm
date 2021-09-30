#include<stdio.h>
int FindMax(int A[],int start,int end){
	int mid=(start+end)/2;
	if(A[mid]>A[mid-1]&&A[mid]>A[mid+1]){
		return A[mid];
	}
	else{
		if(A[mid]>A[mid-1]&&A[mid]<A[mid+1]){
			return FindMax(A,mid+1,end);
		}
		else{
			return FindMax(A,start,mid-1);
		}
	}
}
int main(){
	int A[100],n,i,j;
	printf("How many numbers:");
	scanf("%d",&n);
	printf("Enter the numbers:");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	j=FindMax(A,0,n);
	printf("The Maximum number is:%d\n",j);
	return 0;
}