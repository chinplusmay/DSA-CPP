#include<bits/stdc++.h>
using namespace std;

void Insertion(int arr[], int n){
    for(int i = 0; i < n; i++){
        
        int j = i;  // size of each section in array 
        
        while(j > 0 && arr[j-1] > arr[j]){// j>0 bcoz we only want to compare till the 2nd element to the 1st so iterator should be greater than 0th position
            swap(arr[j-1],arr[j]);
            j--;  // swap till we reach the correct position of elemnt for each section of elements in array
        }
        
    }
}


int main(){

//Input
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    Insertion(arr,n);

// Output
    for(int i : arr){
        cout<<i<< ' ';
    }
}