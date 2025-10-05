#include <bits/stdc++.h>
using namespace std;

// same idea from first last occurance
// total occurance = last-fist + 1

int First(vector<int> &arr, int n, int x){
    int low = 0;
    int high = n-1;
    int first = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == x){
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return first;
}
int Last(vector<int> &arr, int n, int x){
    int low = 0;
    int high = n-1;
    int last = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == x){
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return last;
}

int Total(vector<int> &arr, int n, int x){
    int first = First(arr, n, x);
    int last = Last(arr, n, x);
    int ans = last-first+1;
    return ans;
}

int main(){
    int n = 7;
    int k = 13;
    vector < int > a = {3, 4, 13, 13, 13, 20, 40};
    cout << Total(a, n, k);
}