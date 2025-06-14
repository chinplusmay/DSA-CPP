#include<bits/stdc++.h>
using namespace std;

//Brute TC:O(N!xN)
void recurPermute(vector<int>&nums,vector<int>& mp, vector<int>&ds, vector<vector<int>>& ans){
    if(ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i<nums.size(); i++){
        if(mp[i] == 0){
            mp[i] = 1;
            ds.push_back(nums[i]);
            recurPermute(nums, mp, ds, ans);
            mp[i] = 0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &nums){
    vector<vector<int>> ans;

    vector<int> mp(nums.size(), 0);
    vector<int> ds;
    recurPermute(nums, mp, ds, ans);

    return ans;
}

vector<int> Brute(vector<int> &nums){
    vector<vector<int>> res = permute(nums);
    sort(res.begin(), res.end());
    for(int i = 0; i<res.size(); i++){
        if(res[i] == nums){

            if(i == res.size() - 1) return res[0];  // if it is last permutation we return the first permutation
            else{
                return res[i+1]; // return next permutation
            }
        }
    }
}

vector<int> stlWay(vector<int> nums) {
    if (next_permutation(nums.begin(), nums.end())) {
        return nums;
    } else {
        sort(nums.begin(), nums.end()); // if last permutation, return first
        return nums;
    }
}

vector<int> Optimal(vector<int>&nums){   // tc:O(3N)
    int n = nums.size();
    int indx = -1;
    for(int i = n-2; i>=0; i++){  // find break point
        if(nums[i] < nums[i+1]){
            indx = i;
            break;
        }
    }

    if(indx == -1){ // edge case when there is no break point means its last permutation so we return the first permutation by reversing the last perm
        reverse(nums.begin(), nums.end());
        return nums;
    }

    for(int i = n-1; i>=0; i++){  // swap the break point number with a number who is slighly larger than break point on the right of break point
        if(nums[i] > nums[indx]){
            swap(nums[i] ,nums[indx]);
            break;
        }
    }

    reverse(nums.begin() + indx+1, nums.end());
    return nums;
}




int main() {
    vector<int> v{3,2,4};
    for(auto i : Optimal(v)){
        cout << i << " ";
    }

    return 0;
}