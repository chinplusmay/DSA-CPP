#include <bits/stdc++.h>
using namespace std;

// Armstrong Numbers  
// ex. 371 = 3^3  +  7^3  + 1^3 = 371

int IsArm(int n){
    int temp = n;
    int sum = 0;
    while(temp>0){
        int rem = temp % 10;
        int digcube = (rem*rem*rem);
        sum = sum + digcube;
        temp = temp/10;
    }
    if(n == sum){return 1;}
    return 0;
}

int main(){
    cout<<IsArm(371);
}