#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> board(n, string(n, '.'));
        
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n, false); 
        vector<bool> diag2(2 * n, false); 

        auto backtrack = [&](auto& self, int row) -> void {
            if (row == n) {
                results.push_back(board);
                return;
            }

            for (int col = 0; col < n; ++col) {
                int d1 = row - col + n; 
                int d2 = row + col;

                if (cols[col] || diag1[d1] || diag2[d2]) continue;

                board[row][col] = 'Q';
                cols[col] = diag1[d1] = diag2[d2] = true;

                self(self, row + 1);

                board[row][col] = '.';
                cols[col] = diag1[d1] = diag2[d2] = false;
            }
        };

        backtrack(backtrack, 0);
        return results;
    }
};