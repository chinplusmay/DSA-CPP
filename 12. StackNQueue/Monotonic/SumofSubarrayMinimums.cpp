#include<bits/stdc++.h>
using namespace std;

//Input: arr = [3,1,2,4]
// Output: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.


// here nse psee is of indices not values
vector<int> FindNSE(vector<int>& nums){
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return nse;
}
vector<int> FindPSEE(vector<int>& nums){
    int n = nums.size();
    vector<int> psee(n);
    stack<int> st;
    for(int i = 0; i<n; i++){
        while(!st.empty() && nums[st.top()] > nums[i]){
            st.pop();
        }

        psee[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }
    return psee;
}

int sumSubarrayMins(vector<int>& arr) {
    vector<int> nse = FindNSE(arr);
    vector<int> psee = FindPSEE(arr);
    int mod = 1e9 + 7;
    int total = 0;

    for(int i = 0; i<arr.size(); i++){
        int left = i - psee[i];
        int right = nse[i] - i;
        long long freq = left * right; 
        long long contribution = (freq * arr[i]) % mod; 
        total = (total + contribution) % mod;;
    }
    return (int)total;
}   