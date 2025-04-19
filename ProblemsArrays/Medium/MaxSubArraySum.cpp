#include<bits/stdc++.h>
using namespace std;

int Brute(vector<int>& nums){
    int n = nums.size();
    int maxSum = INT_MIN;
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            // subarray = arr[i.....j]
            int sum = 0;
            for(int k = i; k<j; k++){
                // add all elements of SbArr
                sum += nums[k];
            }
            maxSum = max(sum, maxSum);
        }
    }
    return maxSum;
}

// updated version of brute
int Better(vector<int>& nums){
    int n = nums.size();
    int maxSum = INT_MIN;
    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum += nums[j];
            maxSum = max(sum, maxSum);
        }
    }return maxSum;
}


int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4}; //6
    cout << Better(arr);
}