#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/two-sum/description/

vector<int> Brute(vector<int>& nums, int target){
    for(int i = 0; i<nums.size(); i++){
        for(int j = i+1; j<nums.size(); j++){
            if((nums[i] + nums[j]) == target){
                vector<int> ans = {i,j};
                return ans;
            }
        }
    }return {-1};
}

int main(){
    vector<int> arr = {2,7,11,15}; // 0,1
    int target = 9;

    for(auto it : Brute(arr,target)){
        cout << it <<" ";
    }
}