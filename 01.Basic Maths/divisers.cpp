#include <bits/stdc++.h>
using namespace std;

// BruteForce
vector<int> Diviser1(int n){
    vector<int> Divisers ;

    for(int i = 1; i<=n; i++){
        if(n%i == 0){
            Divisers.push_back(i);
        }
    }return Divisers;
}



// Optimal  O(sqrt(n))
vector<int> Diviser2(int n){
    vector<int> Divesers; 
    for(int i = 1; i*i<=n; i++){     // or sqrt(n)
        if(n%i == 0){
            Divesers.push_back(i);
            if(n/i != i){
                Divesers.push_back(n/i);  // for neglecting 36: 6*6 both are the repeating divisers
            }
        }
    }return Divesers;  // or first sort the Divisers: sort(Diverser.begin(), divises.end())
}


int main(){
    int n = 17;

    // 1
    vector<int> Divs = Diviser1(n); // for each
    for(auto D : Divs){
        cout<< D <<" ";
    }
    cout<<endl;
    //2
    vector<int> Divs2 = Diviser2(n);
    for(int D2 : Divs2){
        cout<< D2 << " ";      // 1,36,2,18,3,12,4....
    }
    
}
