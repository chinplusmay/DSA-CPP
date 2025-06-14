#include<bits/stdc++.h>
using namespace std;

// variartion 2 : Given the row number n. Print the n-th row of Pascal’s triangle

int nCr(int n, int r){
    int ans = 1;
    for(int i = 0; i<r; i++){
        ans = ans * (n-i);
        ans = ans / (i+1);
    }
    return ans;
}

void pascalTriangleBrute(int n){  // brute  tc: O(n*r)
    for(int i = 1; i<=n; i++){
        cout << nCr(n-1, i-1) << " ";
    }
}

void pascalTriangleOpti(int n){ // tc: O(N) where N = given row number
    int ans = 1; // index 0
    cout<<ans<<" ";
    for(int i = 1; i<n; i++){ // 1 to n-1
        ans = ans * (n-i);
        ans = ans / i ;
        cout<<ans<<" ";
    }
    
}




int main(){
    pascalTriangleOpti(5);
}