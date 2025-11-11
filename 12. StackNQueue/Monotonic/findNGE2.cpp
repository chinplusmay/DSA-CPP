#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElementsBr(vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= i+n-1; j++) {
            int indx = j % n;
            if (nums[indx] > nums[i]) {
                nge[i] = nums[indx];
                break;
            }
        }
    }
    return nge;
}

vector<int> nextGreaterElementsOpti(vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n, -1);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i%n]) st.pop();

        if (i < n){
            if(st.empty()) nge[i] = -1;
            else nge[i] = st.top();
        }

        st.push(nums[i%n]);
    }

    return nge;
}




int main() {
    vector<int> nums = {1, 2, 1};
    vector<int> ans = nextGreaterElementsBr(nums);
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
