#include <bits/stdc++.h>
using namespace std;

int Rev(int n){
    int ans = 0;
    while(n>0){
        int rem = n % 10;  // give last digit of n
        ans = ans * 10 + rem;  
        n = n / 10;  // remove last digit from og
    }
    return ans;
}


int main(){
    cout<<Rev(12345);
}