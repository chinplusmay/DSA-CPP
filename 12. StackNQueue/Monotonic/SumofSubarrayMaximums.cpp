#include<bits/stdc++.h>
using namespace std;

vector<int> FindNGE(vector<int>& arr){
    int n = arr.size();
    stack<int> st;
    vector<int> nge(n);

    for(int i = n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }

        nge[i] = st.empty() ? n : st.top();

        st.push(i);
    }
    return nge;
}

vector<int> FindPGEE(vector<int>& arr){
    int n = arr.size();
    stack<int> st;
    vector<int> pgee(n);

    for(int i = 0; i<n; i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            st.pop();
        }

        pgee[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }
    return pgee;
}



int sumSubarrayMaxs(vector<int>& arr) {
    vector<int> nse = FindNGE(arr);
    vector<int> psee = FindPGEE(arr);
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


int main(){
    vector<int> a = {4,2,3,6};
    cout << sumSubarrayMaxs(a);
}