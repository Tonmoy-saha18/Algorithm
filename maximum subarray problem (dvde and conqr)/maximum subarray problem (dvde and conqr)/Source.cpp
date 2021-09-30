#include<iostream>
using namespace std;
struct MyStruct
{
	int left;
	int right;
	int max;
};
struct MyStruct crossing(int low,int mid,int high,int A[]){
	struct MyStruct D;
	int sum=0,l=0,h=0,maxl=-100000,maxr=-10000;
	for(int i=mid;i>=0;i--){
		sum=sum+A[i];
		if(maxl<sum){
			maxl=sum;
			l=i;
		}
	}
	sum=0;
	for(int j=mid+1;j<=high;j++){
		sum=sum+A[j];
		if(maxr<sum){
			maxr=sum;
			h=j;
		}
	}
	D.left=l;
	D.right=h;
	D.max=maxl+maxr;
	return D;
}

struct MyStruct divide(int low,int high,int A[]){
	struct MyStruct B;
	struct MyStruct R;
	struct MyStruct L;
	struct MyStruct C;
	if(low==high){
		B.left=low;
		B.right=low;
		B.max=A[low];
		return B;
	}
	int mid=(low+high)/2;
	R=divide(low,mid,A);
	L=divide(mid+1,high,A);
	C=crossing(low,mid,high,A);
	if(R.max>L.max&&R.max>C.max){
		return R;
	}
	else if(L.max>R.max&&L.max>C.max){
		return L;
	}
	else{
		return C;
	}
}


int main(){
	MyStruct result;
	int A[100],n;
	cout<<"How many numbers!";
	cin>>n;
	cout<<"Enter the numbers:";
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	result=divide(0,n-1,A);
	cout<<"The maximum subarray is from index:"<<result.left<<" to "<<result.right<<endl;
	cout<<"The sum of the maximum subarray is:"<<result.max<<endl;
	return 0;
}

