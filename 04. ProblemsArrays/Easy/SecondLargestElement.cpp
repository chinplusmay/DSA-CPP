#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/second-largest3735/1

int Brute(vector<int> &arr) {  // O(NlogN)
    // sort(buble)
    int n = arr.size();
    for(int i = n-1; i>=1; i--){
        for(int j = 0; j <= i-1; j++){
            if(arr[j] > arr[j+1]){swap(arr[j],arr[j+1]);}
        }
    }

    int largest = arr[n-1];
    int slargest = INT_MIN;

    for(int i = n-1; i >= 0; i--){
        if(arr[i] < largest){    // the first element from the back which is less than(<) largest will be second largest
            slargest = arr[i];
            return slargest;
        }
    }return slargest;  // else return -1
}


int Better(vector<int> arr){  //O(2N)
    int n = arr.size();
    int largest = INT_MIN;
    for(int i= 0; i<n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }

    int slargest = INT_MIN;
    for(int i = 0; i<n; i++){
        if(arr[i] > slargest && arr[i] < largest /*or != largest*/){
            slargest = arr[i];
        }
    }return slargest;
}


int Optimal(vector<int> arr){ // O(N)  
    int n = arr.size();
    int largest = arr[0];
    int slargest = INT_MIN;
    for(int i=0; i<n;i++){
        if(arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        }

        else if(arr[i] < largest && arr[i] > slargest){
            slargest = arr[i];
        }
    }
    return slargest;
}


int main(){
    vector<int> arr = {65,23,1,31,212,74};
    int n = arr.size();

    // cout<< Brute(arr);
    // cout<<Better(arr);
    cout<<Optimal(arr);
}