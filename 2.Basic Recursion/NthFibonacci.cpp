#include <bits/stdc++.h>
using namespace std;

// 0 1 1 2 3 5 8 13

int Fibo(int n){
    // base case
    if(n <= 1){
        return n;
    }

    int last = Fibo(n-1);
    int slast = Fibo(n-2);
    return (last + slast);
}

int main(){
    int n = 3;
    cout<<Fibo(n)<<" ";
}