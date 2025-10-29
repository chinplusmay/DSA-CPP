//Given two integers start and goal. Flip the minimum number of bits of start integer to convert it into goal integer.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // first xor start and goal
    // from the resultant check how many bits are set those many count of bits are req to flip
    
    bool IsSet(int n, int i){
        if((n & (1<<i)) != 0){
            return true;
        }
        return false;
    }

    int minBitsFlip(int start, int goal) {
        int count = 0;
        int num = start ^ goal;
        for(int i = 0; i<32; i++){
            if(IsSet(num, i)){
                count++;
            }
        }return count;
    }
};

int main() {
    int start = 10, goal = 7;
 
    Solution sol; 
    
    int ans = sol.minBitsFlip(start, goal);
    
    cout << "The minimum bit flips to convert number is: " << ans;
    
    return 0;
}
