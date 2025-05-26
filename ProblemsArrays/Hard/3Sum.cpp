#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Brute(vector<int> &nums){
    // tc:O(N3 * log(no. of unique triplets))  sc:O(2 * no. of the unique triplets)
    int n = nums.size();
    set<vector<int>> st;

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans; 
}

vector<vector<int>> Better(vector<int> &nums){  //tc:O(N2 * log(no. of unique triplets))  sc:O(2 * no. of the unique triplets) + O(N)
    int n = nums.size();
    set<vector<int>> vectorSet;
    for(int i = 0; i<n; i++){
        set<int> hashset;
        for(int j = i+1; j<n; j++){
            int third = -(nums[i] + nums[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                vectorSet.insert(temp);
            }

            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(vectorSet.begin(), vectorSet.end()); // copy vectors of vectorSet into ans
    return ans;
}

vector<vector<int>> Optimal(vector<int> &nums){ // tc:O(nlogN) + O(N^2)
    // 2Pointers approach
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i = 0; i<n; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int j = i+1;
        int k = n-1;

        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            if(sum > 0){
                k--;
            }
            else if(sum < 0){
                j++;
            }
            else{//sum=0
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                // to prevent adding of same sums to the array we should move j,k till we find other num than the previous
                while(nums[j] == nums[j-1]) j++; // if j is similar to prev move it forward
                while(nums[k] == nums[k+1]) k--;// if j is similar to prev move it backward
            }
        }
    }
    return ans;
}



int main(){
    vector<int> a = {-1,0,1,2,-1,-4};   //{-1 -1  2}, {-1 0 1} 
    for(auto it : Optimal(a)){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}