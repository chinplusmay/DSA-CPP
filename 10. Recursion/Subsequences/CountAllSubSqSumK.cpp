#include <bits/stdc++.h>
using namespace std;
// ex. [1,2,1] : {1,1} and {2} => 2 subsq,  print count of total subsq sum=k

int CntSubSqSumK(int i, int a[], int sum, int n, int k){
    if(i == n){
        if(sum == k){
            return 1;
        }
        return 0;
    }
    
    sum += a[i];
    int l =  CntSubSqSumK(i+1, a, sum, n, k);
    
    sum -= a[i];
    int r =  CntSubSqSumK(i+1, a, sum, n, k);

    return l+r;
}

int main(){
    int arr[] = {1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ds;
    int k = 2;
    int sum = 0;
    cout<<CntSubSqSumK(0, arr, sum, n, k);
}