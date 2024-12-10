#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
// Union of 2 Sorted array 

vector<int> Brute(vector<int> &a, vector<int> &b) {
    set <int> st; // extra space
    vector <int> ra; // resultant array
    for(int i = 0; i<a.size(); i++){ // a(Logn)
        st.insert(a[i]);
    }
    for(int i = 0; i<b.size(); i++){  // b(logn)
        st.insert(b[i]);
    }
        
    for (auto it : st) {
        ra.push_back(it);
    }
        
    return ra;
        
}



vector<int> Optimal(vector<int> &a, vector<int> &b){
    vector <int> ra; // resultant array  sc(n1+n2) for return the ans
    int n1 = a.size();
    int n2 = b.size();
    int i = 0, j = 0; // pointers for both the arrays

    while(i < n1 && j < n2){ // when both pointers exist in both the arrays
        if(a[i] <= b[j]){
            if(ra.size() == 0 || ra.back() != a[i]){   // if ra have no element OR if a[i] is not already present(Avoid duplicates) in the ra push a[i]
                ra.push_back(a[i]);
            }
            i++;
        }
        

        else{ // if b[j] < a[i]
            if(ra.size() == 0 || ra.back() != b[j]){
                ra.push_back(b[j]);
            }
            j++;
        }
        
        
    }

    while(j < n2){  // when i pointer is exhausted // here no comparision is needed as only one array is left
        if(ra.empty() || ra.back() != b[j]){
            ra.push_back(b[j]);
            j++;
        }
        
    }

    while(i < n1){  // when j pointer is exhausted // here no comparision is needed as only one array is left
        if(ra.empty() || ra.back() != a[i]){
            ra.push_back(a[i]);
            i++;
        }
        
    }

    return ra;
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {1, 2, 3, 6, 7};

    

    for(auto i : Optimal(a,b)){
        cout << i <<" ";
    }
}