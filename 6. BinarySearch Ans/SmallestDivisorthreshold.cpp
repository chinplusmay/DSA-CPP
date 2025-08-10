#include <bits/stdc++.h>
using namespace std;

int Brute(vector<int> &arr, int limit){ //tc:O(max(arr[])*N)
    int maxi = *max_element(arr.begin(), arr.end());
    for(int i = 1; i<=maxi; i++){
    int sum = 0;
        for(int j = 0; j<arr.size(); j++){
            sum += ceil((double)(arr[j]) /(double)(i));
        }
        if(sum <= limit){
            return i;
        }
    }
    return -1;
}

int Optimal(vector<int> &arr, int limit){ //tc:O(log(max(arr[]))*N)
    int maxi = *max_element(arr.begin(), arr.end());

    int low = 1;
    int high = maxi;
    while(low <= high){
        int mid = (low+high)/2;
        int sum = 0;
        for(int i = 0; i<arr.size(); i++){
            sum += ceil((double)(arr[i]) / (double)(mid));
        }

        if(sum <= limit){
            high = mid - 1; // min needed
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> a = {1,2,3,4,5};
    int t = 8;
    cout <<Optimal(a, t);
}