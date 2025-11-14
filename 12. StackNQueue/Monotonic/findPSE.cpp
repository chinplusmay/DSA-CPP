#include <bits/stdc++.h>
using namespace std;
// concept
// prev smallest element, ex. [3, 1, 4, 2] ==> [-1, -1, 1, 1]


vector<int> PSEOpti(vector<int>& nums){
    vector<int> pse(nums.size());
    stack<int> st;
    for(int i = 0; i<=nums.size(); i++){

        while(!st.empty() && st.top() >= nums[i]){
            st.pop();
        }

        if(st.empty()) pse[i] = -1;
        else{
            pse[i] = st.top();
        }

        st.push(nums[i]);
    }
    return pse;
}

int main(){
    vector<int> v = {4,8,5,2,25};
    for(auto i : PSEOpti(v)){
        cout << i << " ";
    }
}