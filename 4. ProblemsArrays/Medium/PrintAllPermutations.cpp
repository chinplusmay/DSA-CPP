#include<bits/stdc++.h>
using namespace std;

void recurPermut(vector<int>&nums, vector<int>&ds, vector<int>&mp, vector<vector<int>>& ans){
    //base
    if(ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i<nums.size(); i++){
        if(!mp[i]){ // is mp[i] == 0

            mp[i] = 1;
            ds.push_back(nums[i]);
            recurPermut(nums, ds, mp, ans);
            mp[i] = 0;
            ds.pop_back();
        }
    }
}



vector<vector<int>> permute(vector<int>& nums){  //tc: O(N! * N)  sc:O(N)
    vector<vector<int>> ans;

    vector<int> ds;
    vector<int> mp(nums.size(), 0);

    recurPermut(nums, ds, mp, ans);

    return ans;
}


int main() {
    vector<int> v{3, 2, 4};
    vector<vector<int>> res = permute(v);

    // Print each permutation
    for (const auto& perm : res) {
        for (const auto& num : perm) {
            cout << num << " "; 
        }
        cout << endl;
    }

    return 0;
}