#include <bits/stdc++.h>
using namespace std;
// Find Missing & Repeating numbers in an array [0,N]

vector<int> BruteMine(vector<int> arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int repeating = -1;
    int missing = -1;

    for(int i = 0; i<n-1; i++){
        if(arr[i] == arr[i+1]){
            repeating = arr[i];
            break;
        }
    }

    if(arr[0] != 1){
        missing = 1;
    }
    else{
        for(int i = 0; i<n-1; i++){
            if(arr[i] == arr[i+1]) continue;
            if((arr[i]+1) != (arr[i+1])){
                missing = (arr[i]+1);
                break;
            }
        }
    }   
    if(missing == -1) missing = arr[n-1]+1;

    return {repeating, missing};
}

vector<int> Brute(vector<int> arr) {
    int n = arr.size();
    int repeating = -1, missing = -1;
    for(int i = 1; i<=n; i++){ // [1,N]
        int count = 0;
        for(int j = 0; j<n; j++){
            if(arr[j] == arr[i]){
                count++;
            }
        }
        if(count == 2) repeating = i;
        else if(count == 0) missing = i;

        if(missing != -1 && repeating != -1) break;
    }
    return{repeating, missing};
}

vector<int> Better(vector<int> arr) { // tc:O(N^2)
    int n = arr.size();
    int repeating = -1, missing = -1;
    int hashArr[n + 1] = {0};

    for(int i = 1; i<=n; i++){
        hashArr[arr[i]]++; 
    }
    for(int i = 1; i<=n; i++){
        if(hashArr[i] == 2) repeating = i;
        if(hashArr[i] == 0) missing = i; 

        if(missing != -1 && repeating != -1) break;
    }

    return{repeating, missing};

}


// using math(Sn)
vector<int> Optimal1(vector<int> arr) {  //tc:O(N)
    long long n = arr.size();
    long long Sn = (n*(n+1))/2;
    long long S2n = (n*(n+1)*(2*n+1))/6;
    long long S = 0, S2 = 0;
    // Calculate S and S2:
    for(int i = 0; i<n; i++){
        S += arr[i];
        S2 += ((long long)arr[i]*(long long)arr[i]);
    }

    //S-Sn = X-Y:
    long long val1 = S - Sn;
    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2n;
    val2 = val2 / val1;  //Find X+Y = (X^2-Y^2)/(X-Y):

    long long x = (val1+val2)/2;
    long long y = x-val1;

    return {(int)x, (int)y};
}




int main()
{
    vector<int> a = {1, 1};
    vector<int> ans = Optimal1(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}