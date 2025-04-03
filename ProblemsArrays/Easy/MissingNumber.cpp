#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/missing-number/description/
// arr[0 to n] ex. {5,0,4,1,3} n=5

int Brute(vector<int> arr){ //O(N^2)
    int n = arr.size();
    for(int i = 0; i<=n; i++){   // all numbers from 0 to n
        int flag = 0;
        for(int j = 0; j<=n-1; j++){ // all indexes of the array
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            return i;
        }
    }

}

int Better(vector<int> arr){ // TC: O(n+n)  SC: O(n) 
    int n = arr.size();
    vector<int> hash(n); // create n size array basically +1 of the array elements and assign all index 0 at initial stage  hash[n+1] = {0}
    for(int i = 0; i<n; i++){
        hash[arr[i]] = 1;
    }

    for(int i = 0; i<=n; i++){
        if(hash[i] == 0){
            return i;
        }
    }
}

int Optimal1(vector<int> arr){
    int n = arr.size();
    int n1 = (n * (n+1)) / 2; // sum of of n numbers
    int n2 = 0;
    for(int i = 0; i<n; i++){
        n2 = n2 + arr[i];    // sum of al the numbers inside the array
    }

    return (n1-n2); // if we subract sum of n number with sum of all numbers in array we will get that remaining/missing number
}

int Optimal2(vector<int> arr){ // O(2N)
    int n = arr.size();
    int xor1 = 0, xor2 = 0;
    for(int i = 0; i<=n; i++){
        xor1 = (xor1 ^ i);
    }

    for(int i = 0; i<n; i++){
        xor2 = (xor2 ^ arr[i]);
    }

    return (xor1 ^ xor2);

}

int Optimal3(vector<int> arr){ // Optimise above by removing for loop for xor1 TC:O(N)
    int n = arr.size();
    int xor1 = 0, xor2 = 0;

    for(int i = 0; i<n; i++){
        xor1 = (xor1 ^ (i+1)); // 0 ^ 1 ^ 2..N
        xor2 = (xor2 ^ arr[i]); // 0 ^ N-1
    }

    return (xor1 ^ xor2);
}

 
int main(){
    vector<int> a = {3,1,0};
    cout<<Optimal3(a);
    return 0;
}