#include <bits/stdc++.h>
using namespace std;

bool IsIso(string s, string t){
    if(s.size() != t.size()) return false;
    unordered_map<char, int> m1;
    unordered_map<char, int> m2;
    for(int i = 0; i<s.size(); i++){
        if(m1.find(s[i]) == m1.end()){
            m1[s[i]] = i;
        } 
        if(m2.find(t[i]) == m2.end()){
            m2[t[i]] = i;
        } 

        if(m1[s[i]] != m2[t[i]]) return false; 
    }return true;
}


int main(){
    string s = "BOO";
    string t = "SEE";
    cout<<IsIso(s,t);
}