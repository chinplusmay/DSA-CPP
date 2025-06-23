
#include <bits/stdc++.h>
using namespace std;

int Brute(vector<int>& arr, int n, int k){ // O(n)
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] == k) return i;
    }
    return -1;
}

//binary search
int Optimal(vector<int>& arr, int n, int k) { // tc:O(logn)
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;

        if(arr[mid] == k) return mid;

        else if(arr[low] <= arr[mid]){
            if(arr[low] <= k && k <= arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        else{ // arr[mid] <= arr[high] right part is sorted
            if(arr[mid] <= k && k <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }return -1;
}

int main(){
    vector<int> a = {7,8,9,1,2,3,4,5,6};
    int n = a.size();
    int k = 1; // 3
    cout << Optimal(a, n, k);
}