#include <bits/stdc++.h>
using namespace std;
// upper bound of x : num > x

int Brute(vector<int> &nums, int x){ // O(N)
    for(int i = 0; i<nums.size()-1; i++){
        if(nums[i] > x) return i;
    }
    return nums.size();
}

int Optimal(vector<int> &nums, int x){ // O(logN)
    int low = 0;
    int high = nums.size()-1;
    int ans = nums.size();
    while(low<=high){
        int mid = (low+high)/2;

        if(nums[mid] > x){
            ans = mid;
            //look for smaller index on the left
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}



int main(){
    vector<int> a = {3,5,8,9,15,19};
    cout<<Optimal(a, 9); //4=>15
}



