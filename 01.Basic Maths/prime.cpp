#include <bits/stdc++.h>
using namespace std;

// based on divisers code //

//Bruteforce

int IsPrime(int n){
    int cnt = 0;
    for(int i = 1; i<=n; i++){
        if(n%i == 0){
            cnt++;
        }
    }
    if(cnt==2){
        return 1;
    }
    return 0;
}


// Optimal (sqrt(n))

int IsPrime2(int n){
    int cnt = 0;
    for(int i=1; i*i<=n;i++){
        if(n%i == 0){
            cnt++;
            if(n/i != i){
                cnt++;
            }
        }
    }
    if(cnt == 2){
        return 1;
    }
    return 0;
}



int main(){
    cout<<IsPrime(17)<<endl;
    cout<<IsPrime2(19)<<endl;
}
