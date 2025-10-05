#include <bits/stdc++.h>
using namespace std;


bool possible(vector<int> arr, int day, int k, int m){  //possible to make a bouquet or not
    int cnt = 0, noOfBouq = 0;
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] <= day){
            cnt++;
        }
        else{
            noOfBouq += (cnt / k);
            cnt = 0;
        }
    }
    noOfBouq += (cnt / k);
    return (noOfBouq >= m);
}

int maximum(vector<int> arr){
    int maxi = INT_MIN;
    for(int i = 0; i<arr.size(); i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}
int minimum(vector<int> arr){
    int mini = INT_MAX;
    for(int i = 0; i<arr.size(); i++){
        mini = min(mini, arr[i]);
    }
    return mini;
}

int Brute(vector<int> arr, int k, int m){ //O((maxi-mini)*N)
    int mini = minimum(arr);
    int maxi = maximum(arr);

    for(int i = mini; i<=maxi; i++){
        if(possible(arr, i, k, m)){
            return i;
        }
    }
    return -1;
}

int Optimal(vector<int> arr, int k, int m){  //O(log(maxi-mini)*N)
    int mini = minimum(arr);
    int maxi = maximum(arr);

    int low = mini;
    int high = maxi;
    while(low<=high){
        int mid = (low+high)/2;

        if(possible(arr, mid, k, m)){
            high = mid - 1; // need to find min
        }
        else{
            low = mid + 1;
        } 
    }
    return low;
}

int main(){
    vector<int> a = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 2, k = 3;
    cout << Optimal(a, k, m);

}