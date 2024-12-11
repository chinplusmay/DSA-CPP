#include<bits/stdc++.h>
using namespace std;

vector<int> Brute(vector<int> &a, int n, vector<int> &b, int m){
    vector<int> ans;
    int vis[m] = {0}; // visited array of size b[m] keeps track of elements in b-array when (a[i] == b[j]) vis[j] = 1 else vis[j] = 0

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(a[i] == b[j] && vis[j] == 0){
                ans.push_back(a[i]);
                vis[j] = 1;
                break; // break from jth loop as element found
            }

            if(a[i] < b[j]) {break;} // int a array:a[i] = 2 and in b array if b[j] > a[i] ex b[j] = 3 no need to iterate more as in sorted array 2 will not be present after 3 so break from it

        }
    }
    return ans;
}

int main(){
    vector<int> a = {1, 2, 2, 4, 5,7,99};
    vector<int> b = {1, 2, 3, 6, 7};

    int n = a.size();
    int m = b.size();

    for(auto i : Brute(a,n,b,m)){
        cout << i <<" ";
    }
}