#include <bits/stdc++.h>
using namespace std;
// ex. [1,2,1] : {1,1} or {2}  print any one subsq that sum = k

bool SubSqSumK(int i, int a[], int sum, vector<int> &ds, int n, int k){
    if(i == n){
        if(sum == k){
            for(int i : ds){
                cout<<i<<" ";
            }
            return true;
        }
        return false;
    }
    
    ds.push_back(a[i]);
    sum += a[i];
    if (SubSqSumK(i+1, a, sum, ds, n, k)) return true;
    
    sum -= a[i];
    ds.pop_back();
    if (SubSqSumK(i+1, a, sum, ds, n, k)) return true;

    return false;
}

int main(){
    int arr[] = {1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ds;
    int k = 2;
    int sum = 0;
    SubSqSumK(0, arr, sum, ds, n, k);
}