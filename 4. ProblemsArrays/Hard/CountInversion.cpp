#include <bits/stdc++.h>
using namespace std;
//Count inversion
int Brute(vector<int>&arr, int n) { // tc ~O(N2)
    int count = 0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i] > arr[j]) count++;
        }
    }
    return count;
}
// Optimal using merge sort/
int Merge(vector<int>&arr, int low,int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    
    int cnt = 0;

    while(left <= mid && right <= high){
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{ // a[left] > a[right] 
            cnt += (mid - left +1);
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
        arr[i] = temp[i - low];
    }
    return cnt;
}

int MergeSort(vector<int>&arr, int low, int high){
    int cnt = 0;
    int mid = (low+high)/2;
    if(low == high) return cnt;
    cnt += MergeSort(arr, low, mid);
    cnt += MergeSort(arr, mid+1, high);

    cnt += Merge(arr, low, mid, high);
    return cnt;
}

int Optimal(vector<int>&arr, int n) { // tc: O(N*logN)   sc:O(N) for temp in mergesort
    return MergeSort(arr, 0, n-1);
    
}




int main()
{
    vector<int> a = {5, 4, 3, 2, 1}; //10
    int n = 5;
    int cnt = Optimal(a, n);
    cout << "The number of inversions is: "
         << cnt << endl;
    return 0;
}