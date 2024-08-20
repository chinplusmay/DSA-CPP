#include <bits/stdc++.h>
using namespace std;

bool Paldr(int n){
    int temp = n;
    int ans = 0;
    while (temp>0)
    {
        int rem = temp % 10;
        ans = ans*10 + rem;
        temp = temp / 10;
    }
    if(n == ans){
        return true;}
    return false;

}

int main(){
    cout<<Paldr(1111);
}