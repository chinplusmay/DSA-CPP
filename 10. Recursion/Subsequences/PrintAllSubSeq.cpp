#include <bits/stdc++.h>
using namespace std;
// ex. [3,1,2] : {}, {3}, {1}, {2}, {3,1}, {3,2}, {1,2}, {3,1,2} : power set

void SubSRec(int i, int a[], vector<int> &ds, int n){
    if(i == n){
        for(int i : ds){
            cout<<i<<" ";
        }
        if(ds.size() == 0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    
    ds.push_back(a[i]);
    SubSRec(i+1, a, ds, n);
    ds.pop_back();

    SubSRec(i+1, a, ds, n);
}

int main(){
    int arr[] = {3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ds;
    SubSRec(0, arr, ds, n);
}