#include <bits/stdc++.h>
using namespace std;

int Brute(int x){
    int ans = 1;
    for(int i = 1; i<=x; i++){
        if(i*i <= x){
            ans = i;
        }
        else{
            break;
        }
    }return ans;
}

int Optimal(int x){
    int ans = 1;
    int low = 1;
    int high = x;
    while(low <= high){
        int mid = (low+high)/2;
        int val = mid*mid;
        if(val == x){
            ans = mid;
            break;
        }
        else if(val < x){
            ans = mid;
            low = mid + 1;
        }

        else{
            high = mid - 1;
        }
    }return ans;
}

int main(){
    int num;
    cin>>num;
    cout<<"sqRt of "<<num<< " is "<< Optimal(num);
}