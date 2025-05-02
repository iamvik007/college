#include<stdio.h>
#define INF 99999

int main(){
    int n,v=1,min,a,b,total=0;
    printf("Enter no of vertices: ");
    scanf("%d",&n);
    int G[n][n];
    int visited [n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    printf("Adjacency matrix: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&G[i][j]);
            if(G[i][j]==0 && i!=j){
                G[i][j]=INF;
            }
        }
    }
    visited[0]=1;
    while(v<n){
        min=INF;
        a=-1,b=-1;
        for(int i=0;i<n;i++){
            if(visited[i]==1){
                for(int j=0;j<n;j++){
                    if(!visited[j] && G[i][j]>0){
                        if(G[i][j]<min){
                            min=G[i][j];
                            a=i;
                            b=j;
                        }
                        
                    }
                }
            }
        }
        if(b==-1) break;
        
        total+=min;
        visited[b]=1;
        v++;
        printf("Edge: %d: (%d --> %d) %d \n",v,a,b,min);
    }
    printf("Total min cost: %d",total);
    
    
    
    
}










