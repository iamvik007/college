#include<stdio.h>

int binarySearch(int arr[],int n,int target){
    int low=0,high=n-1,mid;
    while(low<=high){
        mid = low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]<target){
            low=mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}




int main(){
    int n;
    printf("Enter the no of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        
    }
    
    int target;
    printf("Enter the element to search: ");
    scanf("%d",&target);
    int result=binarySearch(arr,n,target);
    if(result!=-1){
        printf("Element found at index %d \n",result);
    }else{
        printf("Element not found");
    }
    return 0;
}










