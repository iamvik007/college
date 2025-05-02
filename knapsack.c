#include<stdio.h>

int main(){
    int n,cap;
    printf("Enter the no of items: ");
    scanf("%d",&n);
    int p[n],w[n];
    float r[n],total=0;
    for(int i=0;i<n;i++){
        printf("Enter profit and weight of item %c:",i+65);
        scanf("%d %d",&p[i],&w[i]);
         r[i]=(float)p[i]/w[i];
    }
   printf("Enter the capacity: ");
   scanf("%d",&cap);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(r[j]<r[j+1]){
                float temp=r[j];
                r[j]=r[j+1];
                r[j+1]=temp;
                
                int t1=p[j];
                p[j]=p[j+1];
                p[j+1]=t1;
                
                int t2=w[j];
                w[j]=w[j+1];
                w[j+1]=t2;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        total = total+p[i];
        cap=cap-w[i];
        if(cap<0){
            total-=p[i];
            cap-=(w[i]*-1);
            total=total+(float)cap/w[i]*p[i];
            break;
        }
    }
    printf("Maximum profit: %f",total);
    
}
  // 100 5
  // 150 7
  // 50 2
  // 200 10
  // 75 4
















