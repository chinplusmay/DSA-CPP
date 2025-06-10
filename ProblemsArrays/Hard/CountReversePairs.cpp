#include <bits/stdc++.h>
using namespace std;

//i<j and arr[i]>2*arr[j]

int Brute(vector<int>&arr, int n){   // tc:O(N^2)
    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i] > 2*arr[j]) {
                cnt++;
            }
        }
    }
    return cnt;
}

//Optimal using Merge Sort

void Merge(vector<int> &arr, int low, int mid, int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;
    while(left <= mid && right<=high){
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
     while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i<=high; i++){
        arr[i] = temp[i-low];
    }

}

int countPairs(vector<int> &arr, int low, int mid, int high){
    int cnt = 0;
    int right = mid+1;
    for(int i = low; i<=mid; i++){
        while(right <= high && arr[i] > 2*arr[right]) right++;
        cnt += (right - (mid+1));
    }
    return cnt;
}

int MergeSort(vector<int> &arr, int low, int high){
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = (low+high)/2;
    cnt+= MergeSort(arr, low, mid);
    cnt+= MergeSort(arr, mid+1, high);
    cnt+= countPairs(arr, low, mid, high);
    Merge(arr, low, mid, high);
    return cnt;
}

int Optimal(vector<int>&arr, int n){  //tc: O(logN * (N+N)) = O(2N*logN)  sc:O(N)
    int cnt = MergeSort(arr, 0, n-1);
    return cnt;
}


int main()
{
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = Optimal(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}