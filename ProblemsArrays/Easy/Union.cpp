#include<bits/stdc++.h>
using namespace std;


vector<int> Brute(vector<int> &a, vector<int> &b) {
    set <int> st;
    vector <int> ra; // resultant array
    for(int i = 0; i<a.size(); i++){ // a(Logn)
        st.insert(a[i]);
    }
    for(int i = 0; i<b.size(); i++){  // b(logn)
        st.insert(b[i]);
    }
        
    for (auto it : st) {
        an.push_back(it);
    }
        
    return ra;
        
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {1, 2, 3, 6, 7};

    

    for(auto i : Brute(a,b)){
        cout << i <<" ";
    }
}