#include<stdio.h>
#include<stdio.h>
bool Q[8];
int parent[8];
int key[8];
#define max_size 1000000
int ExtractMin(int K[]){
	int min = 10000000,point = -1;
	for(int i=0;i<8;i++){
		if((Q[i]==false)&&(min>key[i])){
			min = key[i];
			point = i;
		}
	}
	return point;
}
void printMST(int graph[][8]){
	int sum = 0;
	printf("Edge______Weight\n");
	for(int i=1;i<8;i++){
		printf("%d  %d  |   %d    |\n",parent[i],i,graph[i][parent[i]]);
		printf("----------------\n");
		sum = sum + graph[i][parent[i]];
	}
	printf("Total sum is:%d|\n",sum);
	printf("----------------\n");
	return;
}
void MSTprime(int graph[][8],int source){
	for(int i=0;i<8;i++){
		key[i] = max_size;
	}
	key[source] = 0;
	for(int i=0;i<8;i++){
		int q = ExtractMin(key);
		Q[q] = true;
		for(int j=0;j<8;j++){
			if(graph[q][j]!=0){
				if((Q[j]==false) &&(graph[q][j]<key[j])){
					parent[j] = q;
					key[j] = graph[q][j];
				}
			}
		}
	}
	printMST(graph);
	return;
}
int main(){
	int graph[8][8] = {{0,14,3,0,0,0,0,0},                     
	                     {14,0,10,0,5,6,0,0},                   
	                     {3,10,0,8,0,0,0,0},
	                     {0,0,8,0,2,0,0,15},
	                     {0,5,0,2,0,4,9,0},
						 {0,6,0,0,4,0,0,0},
						 {0,0,0,0,9,0,0,0},
						 {0,0,0,15,0,0,0,0}};
	for(int i=0;i<8;i++){
		Q[i] = false;
	}
	for(int i=0;i<8; i++){
		parent[i] = -1;
	}
	MSTprime(graph,0);
	return 0;
}




