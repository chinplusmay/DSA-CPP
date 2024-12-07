#include <bits/stdc++.h>
using namespace std;

void Bubble(int arr[],int n){

    for(int i = n-1;i >= 1; i--){

        for(int j = 0; j <= i-1; j++){

            if(arr[j] > arr[j+1]){ swap(arr[j], arr[j+1]); }
        }
    }


}

/*
j     i                   j will run till (i-1) in each round to avoid runtime error see on notes(pg 26-27)
0 -> n-1
0 -> n-2
0 -> n-3
.  .  .
.  .  .
0 -> 1

*/

int main(){

//Input
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    Bubble(arr,n);

// Output
    for(int i : arr){
        cout<<i<< ' ';
    }
}
