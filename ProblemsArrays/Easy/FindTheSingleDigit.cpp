#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/single-number/description/

int Brute(vector<int> arr){
    int n = arr.size();
    for(int i = 0; i<n; i++){
        int count = 0;
        int num = arr[i];
        for(int j = 0; j<n; j++){
            if(arr[j] == num) count++;
        }
        if(count == 1) return num;
    }
} 

int Better(vector<int> arr){
    int n = arr.size();
    int max = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] > max) max = arr[i];
    }
    vector<int> hash(max+1);  // hash of (max element + 1) size and having all elements = 0
    for(int i = 0; i<n; i++){
        hash[arr[i]]++;
    }
    for(int i = 0; i<n; i++){
        if(hash[arr[i]] == 1) return arr[i];
    }
}



int main(){
    vector<int> a = {4,1,2,1,4,9,2};
    cout<<Better(a);
}

