#include<iostream>
#include<algorithm>
struct Greddy
{
	int weight;
	int value;
	int vw;
};
int knapscak(struct Greddy A[],int n,int capacity);
void sort(struct Greddy A[],int n);
int main(){
	struct Greddy A[1000];
	int capacity,n;
	printf("How many itmes:");
	scanf("%d",&n);
	printf("Enter the items:");
	for(int i=0;i<n;i++){
		scanf("%d",&A[i].value);
		scanf("%d",&A[i].weight);
		A[i].vw=A[i].value/A[i].weight;
	}
	int i;
	struct Greddy C;
	for(i=1;i<n;i++){
		int k=A[i].vw;
		C=A[i];
		int j=i-1;
		while(j>=0&&A[j].vw<k){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=C;
	}
	printf("Enter the capacity of knapsack:");
	scanf("%d",&capacity);
	int k=knapscak(A,n,capacity);
	printf("The maximum number they can take is:%d\n",k);
	return 0;
}
int knapscak(struct Greddy A[],int n,int capacity){
	int sum=0;
	for(int i=0;i<n;i++){
		if(capacity!=0){
			if(capacity>=A[i].weight){
				sum=sum+A[i].value;
				capacity=capacity-A[i].weight;
			}
			else{
				sum=sum+((float)capacity/A[i].weight)*A[i].value;
				capacity=0;
			}
		}
		else{
			return sum;
		}
	}
	return sum; 
}


