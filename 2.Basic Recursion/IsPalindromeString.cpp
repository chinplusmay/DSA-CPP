#include <bits/stdc++.h>
using namespace std;

bool fn(int i,string s){
    if(i > s.size() / 2) return true; // base

    if(s[i] != s[s.size()-i-1]) return false;
    return (fn(i+1,s));
}

int main(){
    string s = "MAM";
    cout<< fn(0,s);
}