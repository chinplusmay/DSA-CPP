#include <bits/stdc++.h>
using namespace std;

int Brute(vector<int> &arr){
    int n = arr.size();
    int mini = INT_MAX;
    int index = -1;
    for(int i = 0; i<n; i++){
        if(arr[i] < mini){
            index = i;
            mini = arr[i];
        }
    }
    return mini;
}

int Optimal1(vector<int> &arr){
    int n = arr.size();
    int mini = INT_MAX;
    int index = -1;

    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;

        if(arr[low] <= arr[mid]){
            if(arr[low] < mini){
                index = low;
                mini = arr[low];
            }
            low = mid + 1;
        }
        else{
            if(arr[mid] < mini){
                index = mid;
                mini = arr[mid];
            }
            high = mid - 1;
        }
    }return index;
}

int Optimal2(vector<int> &arr){
    int n = arr.size();
    int mini = INT_MAX;
    int index = -1;

    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;

        if(arr[low] <= arr[high]){
            if(arr[low] < mini){
                index = low;
                mini = arr[low];
            }
            break;
        }

        if(arr[low] <= arr[mid]){
            if(arr[low] < mini){
                index = low;
                mini = arr[low];
            }
            low = mid + 1;
        }
        else{
            if(arr[mid] < mini){
                index = mid;
                mini = arr[mid];
            }
            high = mid - 1;
        }
    }return index;
}


int main(){
    vector<int> a = {4,5,6,7,0,1,2,3}; //4
    cout <<Optimal1(a);
}