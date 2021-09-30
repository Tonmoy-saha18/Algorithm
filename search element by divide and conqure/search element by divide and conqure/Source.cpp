#include<stdio.h>
int search(int A[],int low,int high,int key){
	if(low==high){
		if(A[low]==key){
			return 1;
		}
		return 0;
	}
	else{
		int mid=(low+high)/2;
		int r1=search(A,low,mid,key);
		int r2=search(A,mid+1,high,key);
		return r1+r2;
	}
}
int main(){
	int A[100],n,i;
	printf("How many element:");
	scanf("%d",&n);
	printf("Enter the element:");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	printf("Enter the number to search:");
	int c,k;
	scanf("%d",&c);
	k=search(A,0,n,c);
	if(k==0){
		printf("Not Found\n");
	}
	else{
		printf("Found\n");
	}
	return 0;
}