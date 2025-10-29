#include<bits/stdc++.h>
using namespace std;
// is ith bit is set or not
// ith from right <-

bool IsSet(int n, int i){
    if((n & (1<<i)) != 0){    // or (n & (n>>i))
        return true;
    }
    return false;
}

int SetBit(int n, int i){
    int mask = 1 << i;
    return n | mask;   // n or (1 << i)
}

int ClearBit(int n, int i){
    int mask = ~(1 << i);
    return n & mask;   // n and ~(1 << i)

}

int ToggleBit(int n, int i){
    int mask = 1 << i;
    return n ^ mask;// n xor (1<<i)
}

int main(){
    cout<<IsSet(4,0)<<endl; // 4:100 0th bit is set(1)

    cout<<SetBit(4, 1)<<endl; // 100 (1st bit set)-> 110 =6

    cout<<ClearBit(6, 1)<<endl; // 110 (1st bit clear)-> 100 =4

    cout<<ToggleBit(9, 1)<<endl; // 1001 (1st bit toggle 0 to 1)-> 1011 = 11
}