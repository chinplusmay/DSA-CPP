#include <bits/stdc++.h>
using namespace std;
// First Occurance = arr[i]>=x
// Last Occurance = arr[i] > x - 1 

int LowerBound(vector<int> &arr, int x){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    } 
    return ans;  
}
int UpperBound(vector<int> &arr, int x){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] > x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }return ans;
}

pair<int, int> firstAndLastPostion1(vector<int> &arr, int n, int x){
    int first = LowerBound(arr, x);
    int last = UpperBound(arr, x) - 1;
    if(first == n || arr[first] != x) return {-1,-1};
    return {first, last};
}


// without using lower and upper bound 

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

pair<int, int> firstAndLastPostion2(vector<int> &arr, int n, int x){
    int first = First(arr, n, x);
    if(first == -1) return {-1,-1};
    int last = Last(arr, n, x);
    return {first, last};
}



int main() {
    int n = 7;
    int k = 13;
    vector < int > a = {3, 4, 13, 13, 13, 20, 40};

    // Get first and last position of 'k' (13 in this case)
    pair<int, int> result = firstAndLastPostion2(a, n, k);

    cout << "First occurrence: " << result.first << endl;
    cout << "Last occurrence: " << result.second << endl;

  return 0;
}