#include <bits/stdc++.h>
using namespace std;

void Selection(int arr[],int n){
    // n = sizeof(arr);
    for(int i=0;i < n-1;i++){
        int min = i;

        for(int j = i; j < n ;j++){
            if(arr[min] > arr[j]){ min = j; }
        }
        swap(arr[min],arr[i]);
    }
}

int main(){
    int arr[5] = {13,2,46,8,1};
    Selection(arr,5);
    for(int a : arr){
        cout<< a <<' ';
    }
    
}