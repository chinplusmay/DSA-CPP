#include<bits/stdc++.h>
using namespace std;
// elements occuring more than floor(N/3) times
// there can only be max 2 numbers as majority(n/3)


vector<int> Brute(vector<int> nums) { //tc:O(n^2) sc:O(1) const space of 2
    int n = nums.size();
    vector<int> ansList;
    for(int i = 0; i<n; i++){
        if(ansList.size() == 0 || ansList[0] != nums[i]){
            int count = 0; 

            for(int j = 0; j<n; j++){
                if(nums[j] == nums[i]) count++;
            }
            if(count > (n/3)) ansList.push_back(nums[i]);
        }
        if(ansList.size() == 2) break;
    }

    return ansList;
}

vector<int> Better(vector<int> nums) { // tc:O(NlogN) || O(N)unordered map , sc:O(N)
    int n = nums.size();
    vector<int> ansList;
    map<int, int> hash;
    for(int i = 0; i<n; i++){
        hash[nums[i]]++;

        if(hash[nums[i]] > (n/3)){
            ansList.push_back(nums[i]);
        }
        if(ansList.size() == 2) break;
    }
    return ansList;
}


int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = Better(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}