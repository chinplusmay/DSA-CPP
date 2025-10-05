#include <bits/stdc++.h>
using namespace std;
//Agressive Cows
bool CanWePlace(vector<int> &stalls, int distance, int cows){
    int cntCows = 1;
    int last = stalls[0];
    for(int i = 1; i<stalls.size(); i++){
        if(stalls[i]-last >= distance){
            cntCows++;
            last = stalls[i];
        }
        if(cntCows >= cows) return true;
    }return false;

}

int Brute(vector<int> &stalls, int cows){ // O(NlogN) + O(N *(max(stalls[])-min(stalls[])))
    sort(stalls.begin(), stalls.end());
    int limit = stalls[stalls.size()-1] - stalls[0];
    for(int i = 1; i<=(limit); i++){
        int possible = CanWePlace(stalls, i, cows);
        if(!possible){
            return (i-1);
        }
    }return limit;
}

int Optimal(vector<int> &stalls, int cows){ //  O(NlogN) + O(N * log(max(stalls[])-min(stalls[])))
    sort(stalls.begin(), stalls.end());
    int limit = stalls[stalls.size()-1] - stalls[0];
    int low = 1;
    int high = limit;
    while (low<=high){
        int mid = (low+high)/2;
        if(!CanWePlace(stalls, mid, cows)){
            high = mid - 1;
        }
        else{
            low = mid + 1; // need to find max
        }
    }return high; // opp polarity
    
}


int main(){
    vector<int> s = {0,3,4,7,10,9};
    int cows = 4;
    cout<<Optimal(s, cows);
}