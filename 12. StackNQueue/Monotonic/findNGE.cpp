#include <bits/stdc++.h>
using namespace std;
// concept
// next greater element, ex. [2,3,5,1,4] ==> [3,5,-1,4,-1]


// brute
vector<int> findNGEbrute(vector<int>& nums){ // tc: O(n^2)
    vector<int> nge(nums.size(), -1);

    for(int i = 0; i<nums.size(); i++){
        for(int j = i+1; j<nums.size(); j++){
            if(nums[j] > nums[i]){
                nge[i] = nums[j];
                break;
            } 
        }
    }return nge;
}



// (monotonic stack) opti
vector<int> findNGE(vector<int>& nums){ // tc, sc : O(2n)
    vector<int> nge(nums.size());//sc:O(N) for returning ans
    stack<int> st; //sc:O(N)
    for(int i = nums.size()-1; i>=0; i--){
        
        while(!st.empty() && st.top() <= nums[i]){ // time O(N)
            st.pop(); 
        }

        if(st.empty()) nge[i] = -1;

        else{
            nge[i] = st.top();
        }

        st.push(nums[i]);  //both push and pop time will sum up to O(n)
    }
    return nge;
}

int main(){
    vector<int> v = {3,1,4,2};
    for(auto i : findNGEbrute(v)){
        cout << i << " ";
    }
}