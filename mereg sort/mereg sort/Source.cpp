#include<stdio.h>
void merge(int A[],int low,int mid,int high);
void mergesort(int A[],int low,int high);
int main(){
	int n,A[100],i;
	printf("Enter how many numbers?");
	scanf("%d",&n);
	printf("Enter the numbers:");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	mergesort(A,0,n-1);
	printf("Array after sort:");
	for(i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
}
void mergesort(int A[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		mergesort(A,low,mid);
		mergesort(A,mid+1,high);
		merge(A,low,mid,high);
	}
}
void merge(int A[],int low,int mid,int high){
	int n1=mid-low+1;
	int n2=high-mid;
	int L[100],R[100];
	int i,j,k;
	for(i=0;i<n1;i++){
		L[i]=A[low+i];
	}
	for(j=0;j<=n2;j++){
		R[j]=A[mid+1+j];
	}
	i=0;
	j=0;
	L[n1]=100000;
	R[n2]=100000;
	for(k=low;k<=high;k++){
		if(L[i]<R[j]){
			A[k]=L[i];
			i++;
		}
		else{
			A[k]=R[j];
			j++;
		}
	}
}