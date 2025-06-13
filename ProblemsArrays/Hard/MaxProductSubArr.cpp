#include <bits/stdc++.h>
using namespace std;

int Brute(vector<int> &nums) { //tc:O(N^3)
    int n = nums.size();
    int res = -1;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            int prod = 1;
            for(int k = i; k<=j; k++){
                prod *= nums[k];
                res = max(prod, res);
            }
        }
    }
    return res;
}

int Better(vector<int> &nums) { //tc:O(N^2)
    int n = nums.size();
    int res = -1;
    for(int i = 0; i<n; i++){
        int prod = nums[i];
        for(int j = i+1; j<n;j++){
            prod *= nums[j];
            res = max(prod, res);
        }
    }return res;
}

int Optimal(vector<int> &nums) { //tc:O(N)
    int n = nums.size();
    int pre = 1;
    int suff = 1;
    int ans = INT_MIN;
    for(int i = 0; i<n; i++){
        if(pre == 0) pre = 1;
        if(suff == 0) suff = 1;

        pre *= nums[i];
        suff *= nums[n-i-1];

        ans = max(ans, max(pre, suff));
    }
    return ans;
}




int main(){
    vector<int> nums = {1,2,-3,0,-4,-5}; //20
    cout<<"The maximum product subarray: "<<Brute(nums);
    return 0;
}