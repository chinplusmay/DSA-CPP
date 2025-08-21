#include <bits/stdc++.h>
using namespace std;


string Brute(string s){ //tc, sc O(n)
    string ans;
    stack<string> st;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == ' ') continue;
        string word;
        while(i < s.size() && s[i] != ' '){
            word += s[i];
            i++;
        }
        st.push(word);
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
        if(!st.empty()) ans += " ";
    }
    return ans;
}

string Optimal(string s){ //tc:O(N) sc:O(1)
    reverse(s.begin(), s.end());  // reverse whole string
    int left = 0, right = 0, i = 0;
    int n = s.size();
    while(i<n){
        while(i<n && s[i] == ' ') i++; // skip spaces
        if(i == n) break;
        while(i < n && s[i] != ' '){
            s[right++] = s[i++];
        }
        reverse(s.begin()+left, s.begin()+right);  // reverse word
        s[right++] = ' ';
        left = right;
        i++;
    }
    s.resize(right-1); // remove the trailing space
    return s;
}

int main(){
    string s = "  Hello World ";
    cout<< Optimal(s);
}