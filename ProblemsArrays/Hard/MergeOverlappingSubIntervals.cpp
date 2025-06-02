#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brute(vector<vector<int>> &arr) { // tc: O(NlogN)+O(2n)   sc:O(N)
    int n = arr.size();
    vector<vector<int>> ans;
    //sort the array
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i<n; i++){
        int start = arr[i][0];
        int end = arr[i][1];

        //Skip all the merged intervals:
        if( !ans.empty() && end <= ans.back()[1] ) continue;

        for(int j = i+1; j<n; j++){
            if(arr[j][0] <= end){
                end = max(arr[j][1],end);
            }
            else{
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}
    
    vector<vector<int>> optimal(vector<vector<int>> &arr) { //tc:O(N*logN) + O(N)=> O(N)    sc:O(N)
    int n = arr.size();
    vector<vector<int>> ans;
    //sort the array
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i<n; i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back({arr[i][0], arr[i][1]});
        }
        else{ // if it is overlapping
            ans.back()[1] = max(arr[i][1], ans.back()[1]);
        }
    }
    return ans;
}


int main(){
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = optimal(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}