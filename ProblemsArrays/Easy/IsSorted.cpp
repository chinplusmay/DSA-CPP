#include<bits/stdc++.h>
using namespace std;


int Brute(vector<int> arr,int n){ // O(NlogN + N)
// Create a copy of array then sort the og array then check both are sorted or not
    vector<int> temp(arr);
    for(int i = n-1; i >= 1; i--){
        for(int j = 0; j<i-1; j++){
            if(arr[j] > arr[j+1]){swap(arr[j], arr[j+1]); }
        }
    }

    for(int i = 0; i<n; i++){
        if(arr[i] != temp[i]){
            return 0;
        }
    }
    return 1;

}


int Optimal(vector<int> arr,int n){
    if(n <= 1) return 1;
    for(int i = 0; i < n-1 ; i++){// will till n-1 due to arr[i+1]
        if(arr[i] > arr[i+1]) { return 0;}
    }
    return 1;
}





int main(){
    vector<int> arr = {0,0,0,1};
    int n = arr.size();
    // cout << Brute(arr,n);
    cout << Optimal(arr,n);

}

