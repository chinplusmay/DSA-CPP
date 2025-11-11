#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElementBrute(vector<int>& nums1, vector<int>& nums2) { // tc:O(N^2)
        vector<int> nge(nums1.size(), -1);
        for(int i = 0; i<nums1.size(); i++){
            int ele = 0;
            while(nums1[i] != nums2[ele]){
                ele++;
            }
            for(int j = ele; j<nums2.size(); j++){
                if(nums2[j] > nums1[i]){
                    nge[i] = nums2[j];
                    break;
                }
            }
            
        }return nge;
    } 

// monotonic stack
vector<int> nextGreaterElementOptimal(vector<int>& nums1, vector<int>& nums2) { // sc, tc:O(2N)
        vector<int> nge(nums1.size()); // main ans

        unordered_map<int, int> nextGreaterMap; // maps each number from num2 to its next greater element
        stack<int> st;
        for(int i = nums2.size()-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()) nextGreaterMap[nums2[i]] = -1;

            else{
                nextGreaterMap[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        for(int i = 0; i<nums1.size(); i++){
            nge[i] = nextGreaterMap[nums1[i]];
        }

        return nge;

}   

int main(){
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    for(auto i : nextGreaterElementOptimal(nums1,nums2)){  //[-1,3,-1]
        cout << i << " ";
    }
}