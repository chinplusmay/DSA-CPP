#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/two-sum/description/

int Brute(vector<int>& nums){ //O(n^2)
    int maxProfit = 0;
    for(int i = 0; i<nums.size(); i++){
        for(int j = i+1; j<nums.size(); j++){
            if(nums[j] > nums[i]){
                int cost = nums[j] - nums[i];
                maxProfit = max(maxProfit, cost);
            }
        } 
    }return maxProfit;
}


int Optimal(vector<int>& nums){ //O(n)
    int mini = nums[0];
    int maxProfit = 0;
    for(int i= 0; i<nums.size(); i++){
        int cost = nums[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, nums[i]);
    }
    return maxProfit;
} 


int main(){
    vector<int> a = {7,1,5,3,6,4};  //6-1 = 5
    cout<<Brute(a);
}