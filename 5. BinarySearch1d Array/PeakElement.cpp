#include <bits/stdc++.h>
using namespace std;
int Brute(vector<int> &arr) { //O(N)
    int n = arr.size();
    if(n == 1) return 0;

    for(int i = 0; i<n; i++){
        if((i == 0 || arr[i-1] < arr[i])
            && (i == n-1 || arr[i] > arr[i+1])){
                return i;
            }
    }
    return -1;
}

int Optimal(vector<int> &arr) { //O(logN)
    int n = arr.size();
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;
    int low = 1, high = n-2;
    while(low <= high){
        int mid = (low+high)/2;

        if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) return mid;

        else if(arr[mid] < arr[mid+1]){ // we are in left(increasing curve-> peak is on right)
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return -1;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1}; //7
    int ans = Optimal(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}