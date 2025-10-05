// GCD (greatest Common Factor) or HCF 

/*
12,26 = 2     4,6 = 2     11,13 = 1(default)  

we need to iterate till the smallest number only coz after smallest number it is not possible to be a common factor of both
ex. 4,6 > 1,*2*,3,4,/5/ after 4 any num cannot be a common factor 
*/
#include <bits/stdc++.h>
using namespace std;

int GCD(int n1, int n2){
    int ans = 1;  // default when both no are prime (7,15 = 1)
    for(int i = 1; i <= min(n1,n2); i++){
        if(n1 % i == 0 && n2 % i == 0){
            ans = i;
        }
    }return ans;
}




int GCDrev(int n1,int n2){
    int ans = 1;
    for(int i = min(n1,n2); i >= 1; i--){
        if(n1 % i == 0 && n2 % i == 0){
            ans = i;
            break;  // we will break as we are going in reverse we will first get the highest common factor      <-
        }
    }return ans;
}

int main(){
    cout<<GCD(4,6);
    cout<<endl;
    cout<<GCDrev(4,6);
}