#include<bits/stdc++.h>
using namespace std;

void Brute(vector<int>& nums) {
    int n = nums.size();
    vector <int> temp(n);   // Extra space O(N)
    int j = 0;
    for(int i = 0; i<n; i++){
        if(nums[i] != 0){ // handels non zero elements (-ve,+ve)
            temp[j] = nums[i];
            j++;
        }
       }

    while(j<n){
        temp[j] = 0;
        j++;
    }

    for(int i = 0; i<n; i++){
        nums[i] = temp[i];
    }
}

void Optimal1(vector<int>& nums){   // tc-O(n) sc-O(1)
    int n = nums.size();
    int i = 0;
    for(int j = 0; j<n; j++){
        if(nums[j] != 0){
            nums[i] = nums[j];
            i++;
        }
    }
    while(i<n){
        nums[i] = 0;
        i++;
    }
}

void Optimal2(vector<int>& nums){
    int n = nums.size();
    int j = -1; // worst if no zero in array
    for(int i = 0; i<n; i++){ // Find first Zero element j index
        if(nums[i] == 0){
            j = i;
            break;
        }
    }

    for(int i = j+1; i<n; i++){
        if(j == -1) {return;} // if no zeros in array
        if(nums[i] != 0){
            swap(nums[i], nums[j]);
            j++;
        }
    }

}



int main(){
    vector<int> arr = {0,1,0,3,12};
    int n = arr.size();
    // Brute(arr);
    Optimal1(arr);
    // Optimal2(arr);
    

    for(int i : arr){
        cout << i << ' ';
    }

}