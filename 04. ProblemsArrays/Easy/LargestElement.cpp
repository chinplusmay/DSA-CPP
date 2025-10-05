#include <bits/stdc++.h>
using namespace std;

// Brute Force

// Sort the arr then arr[n-1] is the largest elemnt

int Brute(vector<int> &arr) {
        // Selection Sort
        int n = arr.size();
        for(int i = 0; i<n-1; i++){
            int min = i;
            for(int j = i; j<n; j++){
                if(arr[min] > arr[j]){
                    min = j;
                }
            }
            swap(arr[min], arr[i]);
        }
        // find largest
        return (arr[n-1]);


    }

int Optimal(vector<int> &arr){
    int n = arr.size();
    if(n == 0){return -1;}
    int max = arr[0];
    for(int i = 0; i<n;i++){
        if(max < arr[i]){
            max = arr[i];
        }

    }
    return max;
}



int main() {
	vector<int> arr = {45,1,6,12,121,3};
    // cout<<Brute(arr);
    cout<<Optimal(arr);

    
    

}