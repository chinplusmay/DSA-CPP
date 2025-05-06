#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> Brute(vector<vector<int>> &mat, int n){ // tc:O(n^2)  sc:O(n^2)
    vector<vector<int>> ans(n, vector < int > (n, 0)); // fill matrix with zeroes
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            ans[j][(n-1)-i] = mat[i][j]; // formula derived by dry run see pg 77
        }
    }

    return ans;
}

vector<vector<int>> Optimal(vector<vector<int>> &mat, int n){ // tc:O(N*N) + O(N*N) for transpose, for reverse
    // transpose matrix O(n/2) * O(n/2)
    for(int i = 0; i<n-1; i++){ // i: 0 to n-2
        for(int j = i+1; j<n; j++){ // j: i+1 to n-1
            swap(mat[i][j], mat[j][i]);
        }
    }

    // reverse each row  O(n * n/2)
    for(int i = 0; i<n; i++){
        // mat[i] is a row
        reverse(mat[i].begin(), mat[i].end());
    }
    return mat;
}   


int main(){
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    for(auto it : Optimal(matrix, 3)){
        for(auto i : it){
            cout << i << " ";
        }
        cout<<endl;
    }

}