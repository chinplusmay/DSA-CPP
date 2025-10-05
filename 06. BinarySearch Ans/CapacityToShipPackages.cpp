#include <bits/stdc++.h>
using namespace std;

int FindDays(vector<int> &weights, int capacity){
    int load = 0;
    int days = 1;
    for(int i = 0; i < weights.size(); i++){
        if(load+weights[i] > capacity){
            days ++;
            load = weights[i];
        }
        else{
            load += weights[i];
        }
    }return days;
    
}


int Brute(vector<int> & weights, int d){ // tc:O((sum-max)+1 * N)
    int maxW = *max_element(weights.begin(), weights.end());
    int sumW = accumulate(weights.begin(), weights.end(), 0);

    for(int i = maxW; i <= sumW; i++){
        int Days = FindDays(weights, i);
        if(Days <= d){
            return i; // capacity
        }
    }
    return -1;
}

int Optimal(vector<int> & weights, int d){ // tc:O(N * log(sum(weights[]) - max(weights[]) + 1))
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while(low<=high){
        int mid = (low+high)/2;
        int days = FindDays(weights, mid);

        if(days <= d){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }return low; //opp polarity

}


int main(){
    vector<int> w = {5,4,5,2,3,4,5,6};
    int d = 5;
    cout<<Optimal(w, d);
    return 0;
}