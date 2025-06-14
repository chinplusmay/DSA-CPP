#include<bits/stdc++.h>
using namespace std;

vector<int> Optimal(vector<vector<int>> mat) {
    int n = mat.size();  // number of rows
    int m = mat[0].size();  // number of columns
    vector<int> ans;
    int top = 0, bottom = n - 1, left = 0, right = m - 1;

    while (left <= right && top <= bottom) {
        //left to right across the top row
        for (int i = left; i <= right; i++) {
            ans.push_back(mat[top][i]);
        }
        top++;

        // top to bottom down the right column
        for (int i = top; i <= bottom; i++) {
            ans.push_back(mat[i][right]);
        }
        right--;

        //  right to left across the bottom row (if there's still a row)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        // bottom to top up the left column (if there's still a column)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    
    return ans;
}


int main(){
    vector<vector<int>> mat{{1, 2, 3, 4},
                             {5, 6, 7, 8},
	                         {9, 10, 11, 12},
		                     {13, 14, 15, 16}};
		                     
  vector<int> ans = Optimal(mat);

  for(int i = 0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
  }
}