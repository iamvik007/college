#include<stdio.h>
#define INF 9999

int main(){
    int n,min,a=0,b=0,c=1,total;
    printf("Enter no of vertices: ");
    scanf("%d",&n);
    int G[n][n];
    int visited[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    printf("Enter adj matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&G[i][j]);
            if(G[i][j]==0 && i!=j){
                G[i][j]=INF;
            }
        }
    }
    visited[0]=1;
    while(c<n){
        min=INF;
        
        for(int j=0;j<n;j++){
            if(!visited[j] && G[a][j]<min ){
                min=G[a][j];
                b=j;
            }
        }
        if(min==INF){
            printf("No path exists");
            return 0;
        }
        total = total + min;
        a=b;
        visited[b]=1;
        c++;
    }
    if(G[a][0]==INF){
        printf("can't form a valid spanning tree");
        return 0;
    }
    total = total + G[a][0];
    printf("Total cost: %d",total);
    
}

// Enter no of vertices: 4
// Enter adj matrix:
// 0 10 15 20
// 10 0 35 25
// 15 35 0 30
// 20 25 30 0
// Total cost: 80





















