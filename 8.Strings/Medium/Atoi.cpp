//string to a 32-bit signed integer
#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) { //tc:O(N)
    int i = 0;
    long long ans = 0;
    while(i < s.size() && s[i] == ' '){
        i++;
    }
    s = s.substr(i);
    int sign = +1;
    int mx = INT_MAX;
    int mn = INT_MIN;
    if(s[0] == '-') sign = -1;
    i = (s[0] == '+' || s[0] == '-' ? 1 : 0);
    while(i < s.size()){
        if(s[i] == ' ' || !isdigit(s[i])) break;
        ans = ans*10 + (s[i] - '0');
        //rounding
        if(sign == -1 && -1*ans < mn ) return mn;
        if(sign == +1 && +1*ans > mx ) return mx;
        i++;
    }
    return (int)(sign*ans);

}

int main(){
    string s = " -042";
    cout<<myAtoi(s);
}