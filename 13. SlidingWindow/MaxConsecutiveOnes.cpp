#include<bits/stdc++.h>
using namespace std;
//longestOnes
//Given a binary array nums and an integer k,
//return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
// change the que to : find the maximum subarr in which there are k zeroes(which can be flipped) 

int Brute(vector<int>& nums, int k) { //O(N^2)
    int n = nums.size();
    int maxLen = 0;
    for(int i = 0; i<n; i++){
        int zeroes = 0;
        for(int j = i; j<n; j++){
            if(nums[j] == 0){
                zeroes++;
            }
            if(zeroes <= k){
                maxLen = max(maxLen, j-i+1);
            }
        }
    }return maxLen;
}

int Optimal1(vector<int>& nums, int k){ //O(N)
    int n = nums.size();
    int maxLen = 0;
    int zeroes = 0;
    int r = 0, l = 0;

    while(r < n){
        if(nums[r] == 0) zeroes++;

        while(zeroes > k){
            if(nums[l] == 0) zeroes--;
            l++;
        }
        maxLen = max(maxLen, r-l+1);
        r++;
    }return maxLen;
}

int Optimal2(vector<int>& nums, int k){ //O(N)
    int n = nums.size();
    int maxLen = 0;
    int zeroes = 0;
    int r = 0, l = 0;

    while(r < n){
        if(nums[r] == 0) zeroes++;

        if(zeroes > k){
            if(nums[l] == 0) zeroes--;
            l++;
        }

        if(zeroes <= k){
            maxLen = max(maxLen, r-l+1);
        }
        r++;

    }return maxLen;
}


int main(){
    vector<int> v = {1,1,1,0,0,0,1,1,1,1,0};
    cout << Optimal2(v, 2);
}
