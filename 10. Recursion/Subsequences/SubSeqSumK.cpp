#include <bits/stdc++.h>
using namespace std;
// ex. [1,2,1] : {1,1}, {2}

void SubSqSumK(int i, int a[], int sum, vector<int> &ds, int n, int k){
    if(i == n){
        if(sum == k){
            for(int i : ds){
                cout<<i<<" ";
            }
        }
        cout<<endl;
        return;
    }
    
    ds.push_back(a[i]);
    sum += a[i];
    SubSqSumK(i+1, a, sum, ds, n, k);
    
    sum -= a[i];
    ds.pop_back();
    SubSqSumK(i+1, a, sum, ds, n, k);
}

int main(){
    int arr[] = {1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ds;
    int k = 2;
    int sum = 0;
    SubSqSumK(0, arr, sum, ds, n, k);
}