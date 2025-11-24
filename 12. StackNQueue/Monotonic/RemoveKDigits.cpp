#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {  // tc sc : O(N)
        if(num.size() <= k) return "0";

        stack<char> st;
        for(int i = 0; i<num.size(); i++){
            while(!st.empty() && k > 0 && st.top() > num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k > 0){ // if k is still notzero pop from last till k=0
            st.pop();
            k--;
        }

        string res;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        while(res.size() != 0 && res.back() == '0'){
            res.pop_back();
        }

        reverse(res.begin(), res.end());

        if(res.empty()) return "0";
        return res;    
}

int main(){
    string num = "1432219"; //"1219"
    int k = 3;
    cout<<removeKdigits(num, k);
}