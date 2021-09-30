#include<stdio.h>
#include<stdlib.h>
int distance[5];
int parent[5];
bool Q[5];
#define max_num 1000000;
int minkey(){
	int min = max_num;
	int point = -1;
	for(int i=0;i<5;i++){
		if(Q[i]==false&&min>distance[i]){
			min = distance[i];
			point = i;
		}
	}
	return point;
}
void PrintMst(int graph[][5]){
	int sum = 0;
	int j = 0,l;
	int A[10];
	printf("Connected Edge    Path\n");
	printf("----------------------------\n");
	for(int i=1;i<5;i++){
		printf("     %d %d     |   ",j,i);
		l=0;
		A[l]=i;
		l++;
		int s=parent[i];
		A[l]=s;
		l++;
		while(s!=0){
			s=parent[s];
			A[l]=s;
			l++;
		}
		for(int i=l-1;i>=0;i--){
			if(i==0){
				printf("%d",A[i]);
			}
			else{
			    printf("%d->",A[i]);
			}
		}
		printf("\n");
		sum = sum + graph[parent[i]][i];
		printf("----------------------------\n");
	}
	printf("Total sum is:%d\n",sum);
	printf("----------------------------\n");
	return;
}

void Dijkstra(int graph[][5],int source){
	for(int i=0;i<5;i++){
		parent[i] = -1;
		distance[i] = max_num;
	}
	distance[source] = 0;
	for(int i=0;i<5;i++){
		int u = minkey();
		Q[u] = true;
		for(int j=0;j<5;j++){
			if(graph[u][j]!=0){
				if((Q[j]==false)&&((distance[u]+graph[u][j])<distance[j])){
					distance[j] = (distance[u]+graph[u][j]);
					parent[j] = u;
				}
			}
		}
	}
	PrintMst(graph);
}

int main(){
	int graph[5][5] = {{0,10,5,0,0},
	                   {0,0,2,1,0},
	                   {0,3,0,9,2},
	                   {0,0,0,0,4},
	                   {7,0,0,6,0}};
	for(int i=0;i<5;i++){
		Q[i] = false;
	}
	Dijkstra(graph,0);
	return 0;
}