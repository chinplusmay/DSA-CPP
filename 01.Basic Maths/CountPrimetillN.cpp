// count prime numbers till N (n not included)

#include <bits/stdc++.h>
using namespace std;


//brute

bool isPrime(int num){
    int cnt = 0;
    for(int i = 1; i*i<=num; i++){
        if(num % i == 0){
            cnt++;

            if(num / i != i){
                cnt++;
            }
        }
    }
    if(cnt == 2) return true;
    return false;
}

int countPrimesBrute(int n) {
    int cnt = 0;
    for(int i = 2; i<n; i++){
        if(isPrime(i)){
            cnt++;
        }
    }return cnt;
}

// better Sieve of Eratosthenes
int countPrimesBetter(int n){
    int cnt = 0;
    if(n<=2) return 0;
    vector<int> isPrimeArray(n+1, 1);
    isPrimeArray[0] = isPrimeArray[1] = 0;
    for(int i = 2; i<=n; i++){
        if(isPrimeArray[i] == 1){
            for(int j = i*2; j<=n; j+=i){
                isPrimeArray[j] = 0;
            }
        }
    }

    for(int i = 2; i<n; i++){
        if(isPrimeArray[i] == 1) cnt++;
    }
    return cnt;
}

// Optimal Sieve of Eratosthenes

int countPrimesOptimal(int n){
    int cnt = 0;
    if(n<=2) return 0;
    vector<int> isPrimeArray(n+1, 1);
    isPrimeArray[0] = isPrimeArray[1] = 0;
    for(int i = 2; i*i<=n; i++){
        if(isPrimeArray[i] == 1){
            for(int j = i*2; j<=n; j+=i){
                isPrimeArray[j] = 0;
            }
        }
    }

    for(int i = 2; i<n; i++){
        if(isPrimeArray[i] == 1) cnt++;
    }
    return cnt;
}





int main(){
    int n = 7;
    cout<<countPrimesBrute(n)<<endl;
    cout<<countPrimesBetter(n)<<endl;
    cout<<countPrimesOptimal(n)<<endl;

}