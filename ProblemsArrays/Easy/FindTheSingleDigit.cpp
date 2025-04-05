#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/single-number/description/

int Brute(vector<int> arr){
    int n = arr.size();
    for(int i = 0; i<n; i++){
        int count = 0;
        int num = arr[i];
        for(int j = 0; j<n; j++){
            if(arr[j] == num) count++;
        }
        if(count == 1) return num;
    }
} 

int Better(vector<int> arr){
    int n = arr.size();
    int max = 0;
    for(int i = 0; i<n; i++){   // O(n)
        if(arr[i] > max) max = arr[i];
    }
    vector<int> hash(max+1);  // hash of (max element + 1) size and having all elements = 0
    for(int i = 0; i<n; i++){ // O(n)
        hash[arr[i]]++;
    }
    for(int i = 0; i<n; i++){ // O(n)
        if(hash[arr[i]] == 1) return arr[i];
    }
}

// If array have big numbers like 10^9 , 10^10 so we cannot hash them so we use map<long long, int> with bigger datatype

int Better2(vector<int> arr){ // Total TC: O(N*logM) + O(M) M = size of the map M = (N/2)+1
    int n = arr.size();
    map<int,int> mp;
    
    for(int i = 0; i<n; i++){  // TC-> for ordered map NlogM : N elements of array, log M for insertion in map And for unordered map TC:O(N)
        mp[arr[i]]++; // increment of value of map according to occurance in array
    }

    // map will take space of SC: O(N/2 + 1) +1 for that single digit where N is size of array

    for(auto it : mp){  // TC: O(N/2 + 1)
        if(it.second == 1){
            return it.first;  // return key(the actual numbers in array here as index)
        }
    }

}

int Optimal(vector<int> arr){
    int n = arr.size();
    int xora = 0;
    for(int i = 0; i<n; i++){
        xora = (xora ^ arr[i]); // xor of all the elements which occurs twice will get xor'ed to 0 (a ^ a = 0) and a single element will be left alone and be returned 
    }
    return (xora);
}


int main(){
    vector<int> a = {4,4,2,1,2,5,0,0,5};
    cout<<Optimal(a);
}

