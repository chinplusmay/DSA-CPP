#include <bits/stdc++.h>
using namespace std;

int Brute(vector<int> nums, int trgt) {  // tc: ~O(N^3)
    int n = nums.size(); //size of the given array.
    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            int xr = 0;
            for(int k = i; k<=j; k++){  // [i...j]
                xr = xr ^ nums[k];
            }
            if(xr == trgt) cnt++;  
        }
    }
    return cnt;
}

int Better(vector<int> nums, int trgt) {  // tc:O(N^2)
    int n = nums.size();
    int cnt = 0;
    for(int i = 0; i<n; i++){
        int xr = 0;
        for(int j = i;j<n; j++){
            xr = xr ^ nums[j];
            if(xr == trgt) cnt++;
        }
        
    }
    return cnt;
}

int Optimal(vector<int> nums, int k) { //tc:O(N)unordered map or O(N*logN)ordered ,  sc:O(N)
    //preXOR
    int n = nums.size();
    map<int, int> preXORMap;
    preXORMap[0] = 1;
    int xr = 0;
    int cnt = 0;
    for(int i = 0; i<n; i++){
        xr ^= nums[i];
        int rem = xr ^ k;
        if(preXORMap.find(rem) != preXORMap.end()){
            cnt += preXORMap[rem];
        }
        preXORMap[xr]++; 
    }
    return cnt;
}


int main(){
    vector<int> a = {5, 6, 7, 8, 9};
    cout<< Optimal(a, 5);  //4
}