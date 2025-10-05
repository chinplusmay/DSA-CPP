#include<bits/stdc++.h>
using namespace std;

// variation 3 : given n, you have to print the entire pascal's triangle (spacing not necessary)

//using variation 1:

int nCr(int n, int c){
    int ans = 1;
    for(int i = 0; i<c; i++){
        ans = ans * (n-i);
        ans = ans / (i+1);
    }
    return ans;
}
vector<vector<int>> Var1(int n){
    vector<vector<int>> ans;
    for(int row = 1; row<=n; row++){
        vector<int> tempList;
        for(int col = 1; col<=row; col++){
            tempList.push_back(nCr(row-1, col-1));
        }
        ans.push_back(tempList);
    }
    return ans;
}

// using variation 2

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> resRow;
    resRow.push_back(1);

    for(int col = 1; col<row; col++){
        ans = ans * (row-col);
        ans = ans / col;
        resRow.push_back(ans);
    }
    return resRow;
    
}

vector<vector<int>> Var2(int n){
    vector<vector<int>> ans;
    for(int i = 1; i<=n; i++){
        ans.push_back(generateRow(i));
    }

    return ans;
}






int main()
{
    int n = 5;
    vector<vector<int>> ans = Var2(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }
    
    return 0;
}