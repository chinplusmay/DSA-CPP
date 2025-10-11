#include<bits/stdc++.h>
using namespace std;
// tc : O(2^n*k)  k average space for the ds.
// sc : O(k*x)
class Solution {
public:
    void findCombination(int ind, vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& ans) {
        // Base case: If the target becomes 0, we've found a valid combination
        if (target == 0) {
            ans.push_back(ds); // Add current combination to the answer
            return;
        }

        // If the target becomes negative, no valid combination exists
        if (target < 0) return;

        // Try each candidate starting from index 'ind'
        for (int i = ind; i < candidates.size(); i++) {
            // Skip duplicates: If this candidate is the same as the previous one, skip it
            if (i > ind && candidates[i] == candidates[i - 1]) continue;

            // If the current candidate exceeds the target, break out of the loop
            if (candidates[i] > target) break;

            // Include the current candidate and recurse
            ds.push_back(candidates[i]);
            findCombination(i + 1, candidates, target - candidates[i], ds, ans); // Move to the next index
            ds.pop_back(); // Backtrack by removing the last added element
        }
    }

    // Main function to find combinations
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        
        vector<int> ds; // Current combination
        vector<vector<int>> ans; // Result to store all combinations
        findCombination(0, candidates, target, ds, ans);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {10, 1, 2, 7, 6, 5};
    int target = 8;

    // Get the valid combinations
    vector<vector<int>> result = solution.combinationSum2(candidates, target);

    // Print the result
    cout << "The valid combinations are:" << endl;
    for (const auto& combination : result) {
        cout << "[";
        for (size_t i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i != combination.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
