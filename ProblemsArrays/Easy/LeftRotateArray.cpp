#include<bits/stdc++.h>
using namespace std;
// Left rotate array by d times shift

void LeftShiftBrute(vector<int> &arr, int n,int d){  // TC-> O(n+d) & SC-> O(d)
    vector<int> temp(d);
    d = d % n;
    for(int i = 0; i<d; i++){     //tc O(d)
        temp[i] = arr[i];// Sc O(d)  tempo array
    }

    for(int i = d; i<n; i++){  // O(n-d)
        arr[i-d] = arr[i];
    }
    for(int i = 0; i<d; i++){  // copy elements from temp to arr at the back of arr    // O(d)
        arr[(n-d)+i] = temp[i];

    }
    /* OR
    for(int i = n-d; i<n; i++){
        arr[i] = temp[i-(n-d)];
    }
    */
}

// for Optimal fn
void Reverse(vector<int> &arr, int start, int end){
    while(start <= end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void LeftShiftOpti(vector<int> &arr, int n,int d){
    d = d % n;
    Reverse(arr, 0, d-1);
    Reverse(arr, d, n-1);

    Reverse(arr, 0, n-1);
}




int main(){
    vector<int> arr = {1,2,5,1,2};
    int n = arr.size();
    int d = 1;

    // LeftShiftBrute(arr,n,d);
    LeftShiftOpti(arr,n,d);

    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}

