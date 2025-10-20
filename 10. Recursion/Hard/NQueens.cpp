#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //optimal hashing
    void solve2(int col, vector<string>& board, int n,
               vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal,
               vector<vector<string>>& ans) {
        // If all queens are placed
        if (col == n) {
            ans.push_back(board);
            return;
        }

        // Iterate through all rows
        for (int row = 0; row < n; row++) {
            // Check if it's safe to place the queen
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0) {

                // Place the queen
                board[row][col] = 'Q';

                // Mark the row and diagonals
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // Recurse to next column
                solve2(col + 1, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);

                // Backtrack and remove the queen
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }




    // Brute
    bool isSafe(int row, int col, vector<string> &board, int n) {
        // Check all columns to the left in the same row
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 'Q') return false;
        }

        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check lower-left diagonal
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Return true if no attack is possible
        return true;
    }

    // Backtracking function to place queens column by column
    void solve1(int col, vector<string> &board,
               vector<vector<string>> &ans, int n) {
        // If all columns are filled, add current board to answer
        if (col == n) {
            vector<string> temp;
            for (int i = 0; i < n; i++) {
                // Convert row vector to string
                string row(board[i].begin(), board[i].end());
                temp.push_back(row);
            }
            ans.push_back(temp);
            return;
        }

        // Try placing queen in all rows of current column
        for (int row = 0; row < n; row++) {
            // Place queen only if safe
            if (isSafe(row, col, board, n)) {
                // Place queen
                board[row][col] = 'Q';
                // Recurse for next column
                solve1(col + 1, board, ans, n); 
                // Backtrack and remove queen
                board[row][col] = '.';        
            }
        }
    }

    // Main function to call backtracking
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i<n; i++){
            board[i] = s;
        }
        // Start backtracking from column 0
        solve1(0, board, ans, n);
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve2(0, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);
        return ans;
    }
};

int main() {
    Solution obj;

    // Set board size
    int n = 4;

    // Get all solutions
    vector<vector<string>> res = obj.solveNQueens(n);

    // Print each board
    for (auto &board : res) {
        for (auto &row : board) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
