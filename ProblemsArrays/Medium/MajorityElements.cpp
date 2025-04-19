#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/majority-element/submissions/1610041051/

int Brute(vector<int>& nums){
    int n = nums.size();
    for(int i = 0; i<n; i++){
        int count = 0;
        for(int j = 0; j<n; j++){
            if(nums[i] == nums[j]){
                count++;
            }
        }
        if(count > (n/2)) return nums[i];
    }
    return -1;
}

int Better(vector<int>& nums){
    int n = nums.size();
    map<int, int> mpp;
    for(int i = 0; i<n; i++){
        mpp[nums[i]]++;
    }
    for(auto it : mpp){
        if(it.second > (n/2)) return it.first;
    }

    return -1;
}

int Optimal(vector<int>& nums){
    // moore's voting algo
    int n = nums.size();
    int count = 0;
    int ele;
    for(int i = 0; i<n; i++){
        if(count == 0){
            count = 1;    // ele replaced and start with new element in array and count to 1
            ele = nums[i];
        }
        else if(nums[i] == ele) count++;
        else{//nums[i] != ele
            count--;
        }
    } 
    //The element with the most occurrence will remain and the rest will cancel themselves
    // we got the ele of which count survived mean its count doesnt exhausted and new element got picked up
    // now we will check for the ele is it majority in the array
    int count1 = 0;
    for(int i = 0; i<n; i++){
        if(ele == nums[i]) count1++;
    }
    if(count1 > (n/2)) return ele;
    
}



int main(){
    vector<int> arr = {2,2,1,1,1,2,2,2,4}; //2 appeares 5 > 9/2=4
    cout << Optimal(arr);
}