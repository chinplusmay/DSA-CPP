#include<bits/stdc++.h>
using namespace std;

// variation 1 : In this case, we are given the row number r and the column number c, and we need to find out the element at position (r,c). 

int nCr(int n, int r){
    int ans = 1;
    for(int i = 0; i<r; i++){
        ans = ans * (n-i);
        ans = ans / (i+1);
    }
    return ans;
}

int pascalTriangle(int r, int c) { // r row, c col   tc:O(col)
    int res = nCr(r-1, c-1);
    return res;
}


int main()
{
    int r = 5; // row
    int c = 3; // col
    int element = pascalTriangle(r, c);
    cout<< element;
    return 0;
}