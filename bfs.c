#include<stdio.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front=-1,rear=-1;

void enqueue(int value){
    if(rear == MAX -1){
        printf("Queue is full");
    }else{
        if(front==-1){
        front=0;
        }
        queue[++rear]=value;
    }
}

int dequeue(){
    if(front == -1 || front>rear){
        printf("Queue is empty");
        
    }else{
        int value=queue[front];
        front++;
        return value;
    }
    
}

void bfs(int start,int n){
    visited[start]=1;
    enqueue(start);
    while(front<=rear){
        int value=dequeue();
        printf("%d ",value);
        for(int i=0;i<n;i++){
            if(graph[value][i]==1 && visited[i]==0){
                visited[i]=1;
                enqueue(i);
            }
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
    bfs(start,n);
    
}
