#include<stdio.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

void dfs(int start,int n){
    visited[start]=1;
    printf("%d ",start);
    for(int i=0;i<n;i++){
        if(graph[start][i]==1 && visited[i]==0){
            dfs(i,n);
        }
    }
}



int main(){
    int n;
    printf("Enter no of vertices: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    printf("Enter adj Matrix: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    int start;
    printf("Enter starting vertex: ");
    scanf("%d",&start);
    dfs(start,n);
    
}
