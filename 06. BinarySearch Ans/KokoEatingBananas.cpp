#include <bits/stdc++.h>
using namespace std;
// A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.
// Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.
// Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

int findMax(vector<int> &arr){
    int mx = INT_MIN;
    for(int i = 0; i<arr.size(); i++){
        mx = max(mx, arr[i]);
    }
    return mx;
}

int hoursTaken(vector<int> &arr, int bn){ //o(n)
    int ans = 0;
    for(int i = 0; i<arr.size(); i++){
        ans += ceil((double)(arr[i]) / (double)(bn))  ;
    }
    return ans;
}

int Brute(vector<int> &arr, int h){ // tc: maxarrEle(arr)*N gets tle
    int maxi = findMax(arr);
    for(int i = 1; i <= maxi; i++){
        int hours = hoursTaken(arr, i);
        if(hours <= h){
            return i;
        }
    }
    return -1;
}

int Optimal(vector<int> &arr, int h){ // tc: O(N * log(maxarrEle(arr)))
    int maxi = findMax(arr);
    int low = 1;
    int high = maxi;
    while(low <= high){
        int mid = (low+high)/2;
        int hrs = hoursTaken(arr, mid);

        if(hrs <= h){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }return low;
}

int main(){
    vector<int> a = {7, 15, 6, 3};  //5
    cout << Optimal(a, 8);
}