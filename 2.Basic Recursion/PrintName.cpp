#include <bits/stdc++.h>
using namespace std;

// Prnts Name 'N'-times

void f(int i,int n){
    if(i>n){return;}
    cout<<i<<".Name \n";

    f(i+1,n);
}

int main(){
    int n = 5;
    f(1,n);
}
