//Printing the elements of MaxSubArraySum.cpp
#include<bits/stdc++.h>
using namespace std;

int Kadane(vector<int>& nums){
    int n = nums.size();
    int maxSum = INT_MIN;
    int sum = 0;
    int ansStart = -1, ansEnd = -1;
    int start = 0;

    for(int i = 0; i<n; i++){
        if(sum == 0) start = i;
        sum += nums[i];

        if(sum > maxSum){
            maxSum = max(sum, maxSum);
            ansStart = start;
            ansEnd = i;
        }

        if(sum < 0) sum = 0;
    }

    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << nums[i] << " ";
    }
    cout << "]n";
    return maxSum;
}


int main(){
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    long long maxSum = Kadane(arr);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}