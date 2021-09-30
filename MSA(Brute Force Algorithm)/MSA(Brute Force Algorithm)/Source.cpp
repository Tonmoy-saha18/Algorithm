#include<iostream>
using namespace std;
struct MyStruct
{
	int low;
	int high;
	int max;
};
struct MyStruct MSA(int A[],int n){
	struct MyStruct B;
	int sum=0;
	B.max=A[0];
	B.low=-1000;
	B.high=-1000;
	for(int i=0;i<n;i++){
		sum=0;
		for(int j=i;j<n;j++){
			sum=sum+A[j];
			if(sum>B.max){
				B.max=sum;
				B.high=j;
				B.low=i;
			}
		}
	}
	return B;
}
int main(){
	int n,A[100];
	cout<<"How many numbers!";
	cin>>n;
	cout<<"Enter the numbers:";
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	struct MyStruct C=MSA(A,n);
	cout<<"Maximum subarray index is from:"<<C.low<<" to "<<C.high<<endl;
	cout<<"Maximum subarray sum is:"<<C.max<<endl;
	return 0;
}