#include <bits/stdc++.h>
using namespace std;

int FindFloor(vector<int>&nums, int n, int x){
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] <= x){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int FindCeil(vector<int>&nums, int n, int x){
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] >= x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }return ans;
}

pair<int, int> getFloorAndCeil(vector<int>&nums, int n, int x) {
    int ceil = (FindCeil(nums,n, x) == -1) ? -1 : nums[FindCeil(nums,n, x)];
    int floor = (FindFloor(nums, n, x) == -1) ? -1 :nums[FindFloor(nums, n, x)];


    return make_pair(floor,ceil);
}

int main(){
    vector<int> a = {3, 4, 4, 7, 8, 10};
	int n = 6, x = 5;
    pair<int, int> ans = getFloorAndCeil(a,6,5);
    cout<<"Floor And Ceil values :"<<ans.first<<" "<<ans.second;
}