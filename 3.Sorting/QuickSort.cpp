#include<bits/stdc++.h>
using namespace std;

int Partition(int arr[], int low, int high){
    int Pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){ 

        // For Case : we want where there is greater in left or less in left otherwise we move ahead in check 1,2
        while(arr[i] <= Pivot && i<=high-1){  // Check 1
            i++;
        }
        while(arr[j] > Pivot && j>=low+1){ // Check 2
            j--;
        }
        // here the arr[i] will be >= Pivot & arr[j] will be < Pivot so we swap both of them
        if(i < j){ swap(arr[i], arr[j]); }
    }

    swap(arr[low], arr[j]);  // place the Pivot in the right Place  (swap with arr[low] as first we assumed Pivot as arr[low])
    return j;

}

void qS(int arr[], int low, int high){
    if(low < high){

        int pIndex = Partition(arr, low, high);

        qS(arr,low,pIndex-1); // Left Subarray
        qS(arr, pIndex+1, high); // Right Subarray
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }

    qS(arr,0,n-1);

    for(auto& a : arr){
        cout<< a << " ";
    }
}