#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> board(n, string(n, '.'));
        
        // Tracking arrays for column and diagonal conflicts
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n, false); // row - col + n (shifted to avoid negative indices)
        vector<bool> diag2(2 * n, false); // row + col

        // Helper lambda for recursive backtracking
        auto backtrack = [&](auto& self, int row) -> void {
            if (row == n) {
                results.push_back(board);
                return;
            }

            for (int col = 0; col < n; ++col) {
                int d1 = row - col + n; // Offset by n so range is [0, 2n)
                int d2 = row + col;

                if (cols[col] || diag1[d1] || diag2[d2]) continue;

                // Place Queen
                board[row][col] = 'Q';
                cols[col] = diag1[d1] = diag2[d2] = true;

                // Move to next row
                self(self, row + 1);

                // Backtrack / Undo choice
                board[row][col] = '.';
                cols[col] = diag1[d1] = diag2[d2] = false;
            }
        };

        backtrack(backtrack, 0);
        return results;
    }
};