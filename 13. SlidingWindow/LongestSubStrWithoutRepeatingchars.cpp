#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s){
    int maxLen = 0;
    for(int i = 0; i<s.size(); i++){
        vector<int> hash(256, 0);
        for(int j = i; j<s.size(); j++){
            if(hash[s[j]] == 1) break;

            int len = j-i+1;
            maxLen = max(len, maxLen);
            hash[s[j]] = 1;
        }
    }return maxLen;
}

int main(){
    string s = "abcabcbb"; // abc == 3
    cout << lengthOfLongestSubstring(s);
}
