#include<bits/stdc++.h>
using namespace std;

bool LinearSearch(vector<int>&nums, int x){ //for brute
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] == x){
            return true;
        }
    }return false;
}

int Brute(vector<int>&nums){
    int n = nums.size();
    int longest = 1;
    for(int i = 0; i<n; i++){ // loop for selecting first num
        int num = nums[i];
        int count = 1;

        while(LinearSearch(nums, num+1)){
            num++;
            count++;
        }

        longest = max(count, longest);
    }
    return longest;
}

int Better(vector<int>&nums){
    int n = nums.size();
    
    sort(nums.begin(), nums.end()); // first sort the array

    int longest = 1;
    int count = 0;
    int lastSmallest = INT_MIN;
    
    for(int i = 0; i<n; i++){
        if(nums[i]-1 == lastSmallest){  // if current number is the des cendent(next number) of lastSmallest
            count++;
            lastSmallest = nums[i]; // update the last smallest
        }
        //if nums[i] == lastSmallest :it means it is the duplicate of lastSmallest so do nothing 
        else if(nums[i] != lastSmallest){ // if current num is not equal to lastSmallest then then start the count from start and let the curr num be lastSmallest
            count = 1;
            lastSmallest = nums[i];
        }

        longest = max(count, longest);
    }
    return longest;
}

int Optimal(vector<int>&nums){
    int n = nums.size();
    int longest = 1;
    int count = 0;
    unordered_set<int> st;

    for(int i : nums){  // insert elemenmts into the set
        st.insert(i);
    }

    for(auto it : st){
        if(st.find(it-1) == st.end()){ // if it-1(previous element of current element does not contain) its mean it is the starting num
            count = 1;
            int x = it;
            while(st.find(x+1) != st.end()){ // while next elements of starting number exists
                x++;
                count++;
            }
            longest = max(count, longest);
        }
    }return longest;




}


int main(){
    vector<int> a = {100, 200, 1, 2, 4, 3};
    int ans = Optimal(a);
    cout<<ans;


}