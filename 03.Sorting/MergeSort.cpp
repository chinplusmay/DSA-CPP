#include<bits/stdc++.h>
using namespace std;
// Merge Sorting => Divide and Merge

void Merge(vector<int> &arr, int low, int mid, int high){  // Left and Right Pointers at both halves
    vector<int> temp;
    //[low....mid]
    //([mid+1)....high]

    int left = low;
    int right = mid + 1; 

    while(left <= mid && right <= high){   // will execute until one of the halve gets exhausted
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i<=high; i++){

        arr[i] = temp[i-low];

    }


}

void MergeSort(vector<int> &arr, int low, int high){
    int mid = low + (high - low) / 2 ;  // (low + high) / 2
    if(low >= high) return;

    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);

    Merge(arr,low,mid,high);
    
} 








int main(){

//Input
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    MergeSort(arr,0,n-1);

// Output
    for(const auto& i : arr){
        cout<<i<< ' ';
    }
}