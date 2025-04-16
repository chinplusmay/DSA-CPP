#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/two-sum/description/

vector<int> Brute(vector<int>& nums, int target){ // TC: O(N^2)
    for(int i = 0; i<nums.size(); i++){
        for(int j = i+1; j<nums.size(); j++){
            if((nums[i] + nums[j]) == target){
                vector<int> ans = {i,j};
                return ans;
            }
        }
    }return {-1};
}

vector<int> Better(vector<int>& nums, int target){ // for ordered O(N*LogN) for unordered O(N) worst O(N^2)
    int n = nums.size();
    map<int, int> hash; // <value, index>      SC:O(N)
    for(int i = 0; i<n; i++){
        int first = nums[i];
        int second = target - first;
        if(hash.find(second) != hash.end()){   // check for second element in the map
            return { hash[second], i};
        }
        hash[first] = i;   // if remaining second num of first num not in map then push the first to mapp

    }return {-1};
}


int Optimal(vector<int>& nums, int target){   // TC: O(NlogN)+O(N) but here we cannot return index of the 2numbers as array is sorted afterwards 
    int n = nums.size(); // here we are modifying the array
    sort(nums.begin(), nums.end());
    int right = nums[n-1];
    int left = 0;
    while(left < right){
        int sum = nums[left] + nums[right];
        if(sum == target) return 1;
        else if(sum > target) right--;
        else left++;
    }
    return 0;

}

int main(){
    vector<int> arr = {2,7,11,15}; // 0,1
    int target = 9;

    for(auto it : Optimal(arr,target)){
        cout << it <<" ";
    }
}