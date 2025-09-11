#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s){
    int n = s.size();
    if(n == 0) return "";

    int start = 0;
    int maxLen = 1;

    for(int i = 1; i<n; i++){

        // even compare -> i, i+1
        int l = i-1;
        int r = i;
        while(l>=0 && r<n && s[l]==s[r]){
            if(r-l+1 > maxLen){
                maxLen = r-l+1;
                start = l;
            }
            r++;
            l--;
        }

        // odd compare -> i-1, i+1
        l = i-1;
        r = i+1;
        while(l>=0 && r<n && s[l]==s[r]){
            if(r-l+1 > maxLen){
                maxLen = r-l+1;
                start = l;
            }
            r++;
            l--;
        }
    }
    return s.substr(start, maxLen);

}

int main(){
    string s = "babab";
    cout<<longestPalindrome(s);
}