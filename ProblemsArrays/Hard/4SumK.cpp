#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Brute(vector<int> &nums, int target){  // tc:O(N^4)
    int n = nums.size();
    
    set<vector<int>> st;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                for(int l = k+1; l<n; l++){
                    // taking bigger data type
                    // to avoid integer overflow:
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if(sum == target){
                        vector<int> tmp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(tmp.begin(), tmp.end());
                        st.insert(tmp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> Better(vector<int> &nums, int target){ // tc:O(N3*log(M)) M = no. of elements in the set
    int n = nums.size();

    set<vector<long long>> vectorSet;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            set<long long> hashSet;
            for(int k = j+1; k<n; k++){
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if(hashSet.find(fourth) != hashSet.end()){
                    vector<long long> temp = {nums[i], nums[j], nums[k], fourth};
                    sort(temp.begin(), temp.end());
                    vectorSet.insert(temp);
                }

                hashSet.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(vectorSet.begin(), vectorSet.end());
    return ans;
} 

vector<vector<int>> Optimal(vector<int> &nums, int target){ // tc: O(N^3)
    // 2ptrs
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i = 0; i<n; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(int j = i+1; j<n;j++){
            if(j > i + 1 && nums[j] == nums[j-1]) continue;

            int k = j+1;
            int l = n-1;
            
            while(k<l){
                long long sum = nums[i]+nums[j];
                sum += nums[k];
                sum += nums[l];

                if(sum > target){
                    l--;
                }
                else if(sum < target){
                    k++;
                }

                else{
                    vector<int> tmp = {nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(tmp);
                    k++;
                    l--;
                }

                while(k < l && nums[k] == nums[k-1]) k++;
                while(k < l && nums[l] == nums[l+1]) l--;
            }

        }
    }
    return ans;

}



int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = Optimal(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}