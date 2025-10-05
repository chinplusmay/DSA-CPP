#include <bits/stdc++.h>
using namespace std;

int Brute(vector<int> &arr){
    int n = arr.size();
    int mini = INT_MAX;
    for(int i = 0; i<n; i++){
        mini = min(mini, arr[i]);
    }
    return mini;
}

int Optimal1(vector<int> &arr){
    int n = arr.size();
    int mini = INT_MAX;

    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;

        if(arr[low] <= arr[mid]){
            mini = min(mini, arr[low]);
            low = mid + 1;
        }
        else{
            mini = min(mini, arr[mid]);
            high = mid - 1;
        }
    }return mini;
}

int Optimal2(vector<int> &arr){
    int n = arr.size();
    int mini = INT_MAX;

    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;

        if(arr[low] <= arr[high]){
            mini = min(mini, arr[low]);
            break;
        }

        if(arr[low] <= arr[mid]){
            mini = min(mini, arr[low]);
            low = mid + 1;
        }
        else{
            mini = min(mini, arr[mid]);
            high = mid - 1;
        }
    }return mini;
}


int main(){
    vector<int> a = {4,5,6,7,0,1,2,3}; //0
    cout <<Optimal2(a);
}