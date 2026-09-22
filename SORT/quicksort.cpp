#include<iostream>
using namespace std;

void swap(int a,int b){
    int temp;
    temp = a;
    a=b;
    b=temp;
}
int partation(int arr[],int low,int high){
    int pivot =  arr[low];
    int i = low+1;
    int j = high-1;
    while(true){
        while(i<=pivot){
            i++;
        }
        while(j>=pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }else{
            swap(arr[pivot],arr[j]);
        }
        return j;
    }
};
void quicksort(int arr[],int low,int high){
    quicksort(arr,0,low-1);
    quicksort(arr,low+1,high);
}


int main(){
    int arr[]={10,7,8,9,1,5};
    int n =6;

    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}