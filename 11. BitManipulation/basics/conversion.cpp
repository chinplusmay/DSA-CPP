#include<bits/stdc++.h>
using namespace std;

string convert2Binary(int n){ //tc,sc: O(log2N)
    string res = "";
    while(n!=1){
        if(n % 2 == 1) res += '1';
        else res += '0';

        n=n/2;
    }
    res += '1';
    reverse(res.begin(), res.end());
    return res;

}

int convert2Decimal(string str){ // tc: O(len(str))
    int n = 0;
    int len = str.size();
    for(int i = 0; i<len; i++){
        if(str[i] == '1'){
            n += (int)pow(2,len-i-1);
        }
    }return n;
}

int main(){
    int n = 9;
    cout<<convert2Binary(n)<<endl; // 100

    string str = "100";
    cout<<convert2Decimal(str)<<endl; // 100
}