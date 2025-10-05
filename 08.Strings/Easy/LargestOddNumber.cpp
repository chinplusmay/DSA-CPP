#include <bits/stdc++.h>
using namespace std;

string Brute(string num){
    int n = num.size();
    string ans;
    for(int i = n-1; i>=0; i--){
        if(num[i] % 2 != 0){
            for(int j = 0; j<=i; j++){
                ans += num[j];
            }
            // or:  ans = num.substr(0,i+1)
            return ans;
        }
    }return " ";
}

int main(){
    string s = "35427";
    cout<<Brute(s);
}