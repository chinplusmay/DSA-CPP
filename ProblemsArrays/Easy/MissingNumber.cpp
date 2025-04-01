#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/missing-number/description/
// arr[0 to n] ex. {5,0,4,1,3} n=5

int Brute(vector<int> arr){
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


int main(){
    vector<int> a = {3,1,0};
    cout<<Brute(a);
    return 0;
}