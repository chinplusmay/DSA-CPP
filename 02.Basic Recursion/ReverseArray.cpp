#include <bits/stdc++.h>
using namespace std;

void fn(int i, int n, int arr[]){
    if(i>=n/2) return ;
    swap(arr[i], arr[n-i-1]);
    fn(i+1,n,arr);
}

int main(){
    int no;
    cin>>no;
    int n;
    int arr[no];
    for(int i=0;i<no;i++){
        cin>>n;
        arr[i] = n;
    }
    fn(0,no,arr);

    for (int i = 0; i < no; i++)
    {
        cout<<arr[i]<<" ";
    }
    

}