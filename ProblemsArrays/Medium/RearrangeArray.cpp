#include<bits/stdc++.h>
using namespace std;
// Rearrange Array Elements by Sign
vector<int> Brute(vector<int>& nums){ // tc: O(n)+O(n/2) , sc: O(N) (n/2+n/2)
    int n = nums.size();
    vector<int> neg; // sc O(n/2)
    vector<int> pos; // sc O(n/2

    for(int i = 0; i<n; i++){  // O(N)
        if(nums[i] >= 0){
            pos.push_back(nums[i]);
        }
        else{
            neg.push_back(nums[i]);
        }
    }

    for(int i = 0; i<n/2; i++){   // O(n/2)
        nums[i*2] = pos[i];
        nums[(i*2)+1] = neg[i];
    }
        
    return nums;
}

vector<int> Optimal(vector<int>& nums){ // slight impovement only tc: O(n) , sc: O(N)
    int n = nums.size();
    vector<int> ans(n); // sc: O(n)
    int pos = 0;
    int neg = 1;
    for(int i = 0; i<n; i++){ // tc: O(N)
        if(nums[i] > 0){
            ans[pos] = nums[i];
            pos += 2;
        }
        else{
            ans[neg] = nums[i];
            neg += 2;
        }
    }
    return ans;
}


int main(){
    vector<int> a = {1,2,-3,-1,-2,3};
    for(auto i : Optimal(a)){
        cout << i <<" ";
    }
}