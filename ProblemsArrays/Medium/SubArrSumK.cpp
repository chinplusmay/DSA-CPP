#include<bits/stdc++.h>
using namespace std;

int Brute(vector <int> & nums, int k) {  // O(N^3)
    int n = nums.size();
    int count = 0;
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            int sum = 0;
            for(int k = i; k<=j; k++){  // [i...j]
                sum = sum + nums[k];
            }
            if(sum == k){
                count++;
            }
        }
    }return count;
}

int Better(vector <int> & nums, int k) { // O(N^2)
    int n = nums.size();
    int count = 0;
    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum = sum + nums[j];
            if(sum == k){
                count++;
                break;
            }
        }
    }return count;
}

int Optimal(vector <int> & nums, int k) { // order mp: O(N*logN)  unordered mp:O(N)
    int n = nums.size();
    map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0;
    int cnt = 0;

    for(int i = 0; i<n; i++){
        preSum += nums[i];
        int rem = preSum - k;
        if(mpp.find(rem) != mpp.end()){
            cnt += mpp[rem];
        }

        mpp[preSum] += 1;
    }

    return cnt;
}

int main(){
    vector<int> arr = {3, 1, 2, 4}; // 2
    int k = 6;
    cout<<Optimal(arr, k);  
}