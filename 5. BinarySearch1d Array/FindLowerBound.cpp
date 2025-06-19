#include <bits/stdc++.h>
using namespace std;
// lower bound of x : num >= x 
// least index

int Brute(vector<int> &nums, int x){  //O(N)
    for(int i = 0; i<nums.size()-1; i++){
        if(nums[i] >= x) return i;

    }return nums.size();
}


int Optimal(vector<int> &nums, int x){  //O(logN)
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = n; // if no lower bound exist we take last hypothetical index

    while(low <= high){
        int mid = (low+high) / 2;
        if(nums[mid] >= x){
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}


int main(){
    vector<int> a = {3,5,8,15,19};
    cout<< Optimal(a, 9); // 3 => 15
}