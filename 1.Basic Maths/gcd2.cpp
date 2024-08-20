// GCD (greatest Common Factor) or HCF 
// By  Euclidean Algorithm   tc- O(Log (min(a,b))  ) 

/*
    this thrm states:  gcd(a,b) = gcd(a-b,b) provided * a > b *     (greater,smaller)
    ex. gcd(6,4) = gcd(2(6-4),4) == gcd(4,2) = gcd(2,2) = gcd(0,2) = gcd = 2   too many steps
    But this will take too much time to calculate so we will use euclidean modulo algo

    gcd(a,b) = gcd(a % b , b)  a > b
    ex. gcd(6,4) = gcd(6%4 , 4) == gcd(2,4) == gcd(4,2) = gcd(0,2) = gcd = 2   (greater,smaller)
    if one is zero other is the GCD
    We will not swap like in the example but update n1 or n2 
*/


#include <bits/stdc++.h>
using namespace std;

int gcdEUc(int n1, int n2){
    while(n1>0 && n2>0){
        if(n1>n2){n1 = n1%n2;}
        else{
            n2=n2%n1;   // n2>n1
        }

    }
    if(n1 == 0) return n2;
    return n1;   // else if (n2 == 0) 
}

int main() {
    cout<<gcdEUc(13,11);  
    cout<<endl;
    cout<<gcdEUc(4,6);
}