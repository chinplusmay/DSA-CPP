#include<bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>> &mat, int n, int m, int i){
    for(int j = 0; j<m; j++){
        if(mat[i][j] != 0){
            mat[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &mat, int n, int m, int j){
    for(int i = 0; i<n; i++){
        if(mat[i][j] != 0){
            mat[i][j] = -1;
        }
    }
}


vector<vector<int>> Brute(vector<vector<int>> &mat, int n, int m) { //tc:O((N*M)*(N + M)) + O(N*M)
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mat[i][j] == 0){
                markRow(mat, n, m, i);
                markCol(mat, n, m, j);
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mat[i][j] == -1){
                mat[i][j] = 0;
            }
        }
    }
    return mat;
}

vector<vector<int>> Better(vector<vector<int>> &mat, int n, int m) { // tc:O(2*(N*M)), sc:O(N) + O(M)
    vector<int> row(n, 0);
    vector<int> col(m, 0);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mat[i][j] == 0){   // mark ith, jth element of row, col arrays
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(row[i] == 1 || col[j] == 1){
                mat[i][j] = 0;
            }
        }
    }
    return mat;

}

vector<vector<int>> Optimal(vector<vector<int>> &mat, int n, int m) {

    // row[n] -> mat[i][..]
    // col[m] -> mat[..][j]
    
    int col0 = 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mat[i][j] == 0){
                //update the ith row
                mat[i][0] = 0;

                //update the jth col
                if(j != 0){
                    mat[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }

        }
    }

    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(mat[i][j] != 0){
                if(mat[0][j] == 0 || mat[i][0] == 0){
                    mat[i][j] = 0;
                }
            }
        }
    }

    if(mat[0][0] == 0){
        for(int j = 0; j<m; j++){
            mat[0][j] = 0;
        }
    }
    if(col0 == 0){
        for(int i = 0; i<n; i++){
            mat[i][0] = 0;
        }
    }

    return mat;
}

int main(){
    vector<vector<int>> matrix = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    for(auto it : Optimal(matrix, 3, 3)){
        for(auto i : it){
            cout << i << " ";
        }
        cout<<endl;
    }

}