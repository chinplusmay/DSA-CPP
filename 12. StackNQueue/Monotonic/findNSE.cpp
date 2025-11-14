#include <bits/stdc++.h>
using namespace std;
// concept
// next smallest element, ex. [4, 8, 5, 2, 25] ==> [2, 5, 2, -1, -1]

vector<int> NSEOpti(vector<int>& nums){
    vector<int> nse(nums.size());
    stack<int> st;
    for(int i = nums.size()-1; i>=0; i--){

        while(!st.empty() && st.top() >= nums[i]){
            st.pop();
        }

        if(st.empty()) nse[i] = -1;
        else{
            nse[i] = st.top();
        }

        st.push(nums[i]);
    }
    return nse;
}

int main(){
    vector<int> v = {4,8,5,2,25};
    for(auto i : NSEOpti(v)){
        cout << i << " ";
    }
}