#include<stdio.h>
int Frequency(int A[],int low,int high,int key){
	int mid=(low+high)/2;
	if(low==high){
		if(key==A[low]){
			return 1;
		}
		return 0;
	}
	if(low<high){
		int r1=Frequency(A,low,mid,key);
		int r2=Frequency(A,mid+1,high,key);
		return r1+r2;
	}
}
int main(){
	int n,i,j,A[100],m;
	printf("How many numbers?");
	scanf("%d",&n);
	printf("Enter the numbers:");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	printf("Enter the number to search:");
	scanf("%d",&m);
	j=Frequency(A,0,n,m);
	printf("Frequency of the number is:%d\n",j);
	return 0;
}