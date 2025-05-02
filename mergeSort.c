#include<stdio.h>

void merge(int arr[],int l,int mid,int r){
    int i,j,k,temp[100];
    i=l;
    j=mid+1;
    k=l;
    while(i<=mid && j<=r){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }else if(arr[j]<arr[i]){
            temp[k++]=arr[j++];
        }else{
            temp[k++]=arr[i++];
            temp[k++]=arr[j++];
        }
    }
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=r){
            temp[k++]=arr[j++];
        }
        for(int i=l;i<=r;i++){
            arr[i]=temp[i];
        }
    
}

void mergeSort(int arr[],int l, int r){
    if(l>=r) return;
    int mid = l+(r-l)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}




int main(){
    int n;
    printf("Enter the no of element: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    printf("After sorting: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
