#include<bits/stdc++.h>
using namespace std;
//https://www.naukri.com/code360/problems/remove-duplicates-from-sorted-array_1102307
// Remove duplicates from a sorted array and return the size of modified array containg only distinct elemnets

int Brute(int arr[],int n){ // TC-> O(NlogN + N)  and SC -> O(N)
    set<int> st ; // SC-> O(n)
    for(int i = 0; i < n; i++){
        st.insert(arr[i]); // takes log n time to insert so TC-> O(nlog n)
    }

    int k = st.size();
    int index = 0;
    for(auto & a : st){  // O(n)
        arr[index++] = a; // postincrement index = 0 1 2 ----
    }  // adds the distict elements from set to back to array from the start 
       // if arr was arr= {1,1,2,2,3,3,4,4,5,5,5} -> arr= {(1,2,3,4),-,-,-,-,-} arr may have extra elements after distinct but about that we dont care
                                                        // from set
    return k;  // return size of set which have only distinct numbers

}



int Optimal(int arr[],int n){  // Two Pointer approach // TC-> O(N)
    int i = 0; // let first element be distinct element, after i another distinct elemnt will be placed(i will be at distinct element only)
    for(int j = 1; j<n; j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++; // increment i to next ditinct element
        }
    }
    return( i + 1);   // return size of till distinct element reside
}




int main(){
    int arr[] = {1,1,1,1,2,2,2,3,3,3,4,4,5,5};  // duplicates only lie one after another like 2,2 or 1,1 not like 4,-,-,-,4 x
    int n = sizeof(arr)/sizeof(arr[0]);
    /*
    int k = Brute(arr,n);
    for(int i = 0; i < k; i++){  // printing only till distinct elements(size of set: k)
        cout<< arr[i] << " ";
    }
    */
   int k = Optimal(arr,n);
   for(int i = 0; i < k; i++){
    cout << arr[i] << " ";
   }


}