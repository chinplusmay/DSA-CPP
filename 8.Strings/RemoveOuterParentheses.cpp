#include <bits/stdc++.h>
using namespace std;

string Brute(string s){ // tc, sc : O(N)
    stack<char> st;
    string ans;
    for(auto c : s){
        if(c == '('){
            if(st.size() > 0){
                ans += '(';
            }
            st.push('(');
        }
        else{ // )
            if(st.size() > 1){
                ans += ')';
            }
            st.pop();
        }
    }
    return ans;
}

string Optimal(string s){ // tc:O(N) sc:O(1)
    int cnt = 0;
    string ans;
    for(char c : s){
        if(c == '('){
            if(cnt > 0){
                ans += c;
            }
            cnt++;
        }
        else{
            if(cnt > 1){
                ans += c;
            }
            cnt--;
        }
    }return ans;
}

int main(){
    string s = "(()())(())";
    string a = Optimal(s); 
    cout << a << endl;
    return 0;
}
