#include <bits/stdc++.h>
using namespace std;
// concept
// prev greatest element, ex. [2,3,5,1,4] ==> [-1,-1,-1,5,5]

vector<int> PGEOpti(vector<int>& nums){
    vector<int> pge(nums.size());
    stack<int> st;
    for(int i = 0; i<nums.size(); i++){

        while(!st.empty() && st.top() <= nums[i]){
            st.pop();
        }

        if(st.empty()) pge[i] = -1;
        else pge[i] = st.top();

        st.push(nums[i]);
    }
    return pge;
}

int main(){
    vector<int> v = {3,1,4,2};
    for(auto i : PGEOpti(v)){
        cout << i << " ";
    }
}