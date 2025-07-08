#include <bits/stdc++.h>
using namespace std;

int Brute1(vector<int> &arr){ // O(n)
    int n = arr.size();
    if(n == 1) return arr[0];
    for(int i = 0; i<n; i++){
        if(i == 0){
            if(arr[i] != arr[i+1]){
                return arr[i];
            }
        }

        else if(i == n-1){
            if(arr[i] != arr[i-1]){
                return arr[i];
            }
        }
        else{
            if(arr[i] != arr[i-1] && arr[i] != arr[i+1]){
                return arr[i];
            }
        }

    }return -1;
}

int Brute2(vector<int> &arr){  //O(n)  XOR
    int n = arr.size();
    int xr = 0;
    for(int i = 0; i<n; i++){
        xr = (xr ^ arr[i]);
    }
    return xr;
}

int Optimal(vector<int> &arr){  //O(Logn) 
    int n = arr.size();
    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    else if(arr[n-1] != arr[n-2]) return arr[n-1];

    int low = 1, high = n-2;
    while(low <= high){
        int mid = (low+high)/2;

        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];

        else if( // left part (even, odd)
            (arr[mid] % 2 == 1 && arr[mid] == arr[mid-1]) || (arr[mid]%2 == 0 && arr[mid] == arr[mid+1])
        ){
            low = mid + 1;
        }
        else{ // right part
            high = mid - 1;
        }
    }
    return -1;
}


int main(){
    vector<int> a = {1,1,2,3,3,4,4};
    cout<<Optimal(a);
}