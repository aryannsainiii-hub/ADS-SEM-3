#include<iostream>
using namespace std;

void quicksort(int arr[],int s , int e){
    //base case
    if(s>=e){
        return;
    }
    //partitioning
    int pivot=arr[e];
    int i=s-1;
    for(int j=s;j<e;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    quicksort(arr,s,i);
    quicksort(arr,i+2,e);
}

int main(){
    int arr[]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }   
}