#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/max-consecutive-ones/

int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    int max = 0;
    for(int i = 0; i<n; i++){
        if(nums[i] == 1){
            count++;
        }

        if(count>max){
            max = count;
        }
        if(nums[i] == 0){
            count = 0;
        }
    }return max;
}




int main(){
    vector<int> a = {1,1,0,1,1,1};
    cout<<findMaxConsecutiveOnes(a);
    return 0;
}