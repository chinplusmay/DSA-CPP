#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& v){
    string ans = "";
    int n = v.size();
    sort(v.begin(), v.end());       
    string first = v[0], last = v[n-1];
    int minLen = min(first.size(), last.size()); 
    for(int i = 0; i<minLen; i++){
        if(first[i] == last[i]){
            ans += first[i];
        }
        else{
            return ans;
        }
    }return ans;
}

int main(){
    vector<string> s = {"flower","flow","flight"}; //fl
    cout<<longestCommonPrefix(s);
}