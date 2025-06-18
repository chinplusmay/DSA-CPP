#include <bits/stdc++.h>
using namespace std;

int binarySearchIterative(vector<int>& nums, int target) {// O(logN)
    int n = nums.size();
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low+high) / 2;
        if(target == nums[mid]) return mid; 
        else if(target < nums[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}


int fn(vector<int>& nums, int low, int high, int target){
    //base case
    if(low > high) return -1;
    int mid = (low+high) / 2;

    if(target == nums[mid]) return mid;
    else if(target < nums[mid]){
        return fn(nums,low, mid-1 , target);
    }

    return fn(nums, mid+1, high , target);

}

int binarySearchRecursive(vector<int>& nums, int target){// O(logN)
    int ans = fn(nums, 0, nums.size()-1, target);
    if(ans != -1) return ans;
    return -1;
}


int main(){
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    // cout << binarySearchIterative(a, target);
    cout << binarySearchRecursive(a, target);


}