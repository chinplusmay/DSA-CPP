#include<bits/stdc++.h>
using namespace std;
// everything on the right of leader is smaller
// ex. arr = {10,22,12,3,0,6}
// ans = {22,12,6}

vector<int> Brute(vector<int>& nums){ //tc:O(n^2)
    int n = nums.size();
    vector<int> ans;
    for(int i = 0; i<n; i++){
        bool isLeader = true;   // let first num be leader

        for(int j = i+1; j<n; j++){
            if(nums[i] < nums[j]){
                isLeader = false;
                break;
            }
        }
        if(isLeader){
            ans.push_back(nums[i]);
        }
    }
    return ans;
    
}

vector<int> Optimal(vector<int>& nums){ //tc:O()
    int n = nums.size();
    vector<int> ans;
    int max = INT_MIN;
    for(int i = n-1; i>=0; i--){
        if(nums[i] > max){
            max = nums[i];
            ans.push_back(nums[i]);
            
        }
    
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    vector<int> arr = {10,22,12,3,0,6};
    for(auto i : Optimal(arr)){
        cout<< i <<" ";
    }
}