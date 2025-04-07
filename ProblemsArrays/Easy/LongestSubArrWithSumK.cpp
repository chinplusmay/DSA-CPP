#include<bits/stdc++.h>
using namespace std;

int Brute1(vector<int>&nums, int k){  //around O(N^3)
    int n = nums.size();
    int len = 0;
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            int sum = 0;
            for(int e = i; e<=j; e++){  // this loop has very less iterations and keep diminishing so thast why O(n^3) 
                sum += nums[e];
            }
            if(sum == k) len = max(len, j-i+1);
            
        }
    }
    return len;
}

int Brute2(vector<int>&nums, long long k){
    int n = nums.size();
    int len = 0;
    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum += nums[j];
            if(sum == k) len = max(len, j-i+1);
        }
        
    }
    return len;
}

// using presum map  this is teh Optimal solution for +ve's and -ve's
int Better(vector<int>&nums, int k){ //TC: ordered map O(N*Log(N)) unordered:O(N*1) ≈ N*(N)=O(N^2) 1->N if there are lot of collisions in the map search time becomes N
    map<long long, int > preSumMap; // SC: O(N)
    int maxLen = 0;
    long long sum = 0;
    for(int i = 0; i<nums.size(); i++){
        sum += nums[i];

        if(sum == k) maxLen= max(maxLen, i+1);

        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()){  // if rem(already visited) exists in the map
            int len = i - preSumMap[rem];  // current index - index at rem in map(value in map)
            maxLen = max(maxLen, len);
        }

        if(preSumMap.find(sum) == preSumMap.end()){  // add sum to map only if it does not already exist in the map
            preSumMap[sum] = i; // insert in map
        }

    }
    return maxLen;
}

//Two Pointers optimal for zeroes and 
int Optimal(vector<int>&nums, int k){
    int n = nums.size();
    int l = 0, r = 0;
    long long sum = nums[0];
    int maxLen = 0;

    while(r<n){ // r under boundary

        // when sum > k, subract left from sum and move left itr
        while(sum > k && r > l){
            sum -= nums[l];
            l++;
        }

        // update the maxLen
        if(sum == k) maxLen = max(maxLen, r-l+1);

        // move the right itr and keep summing up sum
        r++;
        sum += nums[r];
    }
    return maxLen;
}




int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    cout << Optimal(arr, 10);
}



