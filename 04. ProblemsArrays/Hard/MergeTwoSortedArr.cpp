//Merge two Sorted Arrays Without Extra Space

#include <bits/stdc++.h>
using namespace std;


void Brute(long long arr1[], long long arr2[], int n, int m) { //tc: O(2(n+m))  x sc: O(n+m)
    // violates the extra space
    long long arr3[n+m];
    int left = 0;
    int right= 0;
    int i = 0;
    while(left < n && right<m){
        if(arr1[left] <= arr2[right]){
            arr3[i] = arr1[left];
            i++, left++;
        }
        else{
            arr3[i] = arr2[right];
            i++, right++;
        }
    }
    while(left < n){
        arr3[i++] = arr1[left++];
    }
    while(right < m){
        arr3[i++] = arr2[right++];
    }

    // fill the arr1,arr2 with sorted elements using arr3

    for(int i = 0; i<n; i++){
        arr1[i] = arr3[i];
    }
    for(int i = n; i<n+m; i++){
        arr2[i-n] = arr3[i];
    }
}

void Optimal1(long long arr1[], long long arr2[], int n, int m){ //tc:O(min(n, m)) + O(n*logn) + O(m*logm)
    int left = n-1;
    int right = 0;

    while(left >= 0  && right < m){
        if(arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else{
            break;
        }
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+m);
    
}

void swapIfGreater(long long arr1[], long long arr2[], int left, int right){
    if(arr1[left] > arr2[right]){
        swap(arr1[left], arr2[right]);
    }
    
}

void Optimal2(long long arr1[], long long arr2[], int n, int m){// tc:O((n+m)*log(n+m))
    int gap = ((n+m)/2) + ((n+m) % 2);

    while(gap > 0){
        int left = 0;
        int right = gap+left;

        while(right < (n+m)){
            // both pointers in arr1 and arr2
            if(left < n && right >= n){
                swapIfGreater(arr1, arr2,left, right-n);
            }

            // both pointers in arr1
            else if(right<(n+1)){
                swapIfGreater(arr1, arr1, left, right);
            }

            else{// both pointers in arr2
                swapIfGreater(arr2, arr2, left-n, right-n);
            }
            right++, left++;
        }

        if(gap == 1) break;
        gap = (gap/2) + (gap%2);
    } 
}  



int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    Optimal2(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}