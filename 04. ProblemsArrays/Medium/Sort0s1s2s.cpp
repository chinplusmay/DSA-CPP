#include<bits/stdc++.h>
using namespace std;

vector<int> Brute(vector<int>& nums){ // TC:O(NLogN)  SC:O(1)
    sort(nums.begin(), nums.end());
    return nums;
}


vector<int> Better(vector<int>& nums){ // TC:O(2N)  SC:O(1)
    int n = nums.size();
    int zero = 0;
    int one = 0;
    int two = 0;
    for(int i = 0; i<n; i++){
        if(nums[i] == 0) zero++;
        else if(nums[i] == 1) one++;
        else two++;
    }

    for(int i = 0; i<zero; i++){
        nums[i] = 0;
    }
    for(int i = zero; i<zero+one; i++){
        nums[i] = 1;
    }
    for(int i = zero+one; i<zero+one+two; i++){
        nums[i] = 2;
    }

    return nums;
}

vector<int> Optimal(vector<int>& nums){
    // Dutch nationals flag
    int n = nums.size();
    int low = 0, mid = 0, high = n-1;
    while(mid<high){
        if(nums[mid] == 0){
            swap(nums[mid], nums[low]);
            mid++, low++;
        }
        else if(nums[mid] == 1) mid++;
        else{ //2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
    return nums;

}




int main(){
    vector<int> arr = {2,0,2,1,1,0};
    for(auto i : Optimal(arr)){
        cout << i <<" ";
    }
}