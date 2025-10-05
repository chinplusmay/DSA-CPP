#include <bits/stdc++.h>
using namespace std;

bool Brute(vector<int>& arr, int n, int k){ // O(n)
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] == k) return true;
    }
    return false;
}

bool Optimal(vector<int>& arr, int n, int k){ //O(LogN)
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){  // for duplicates if 3 ptrs are same we deduce the array and continue
            low = low + 1;
            high = high - 1;
            continue;
        }

        if(arr[mid] == k) return true;

        else if(arr[low] <= arr[mid]){
            if(arr[low] <= k && k <= arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(arr[mid] <= k && k <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }return false;
}


int main(){
    vector<int> a = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int n = a.size();
    int k = 3; // true(1)
    cout << Optimal(a, n, k);
}