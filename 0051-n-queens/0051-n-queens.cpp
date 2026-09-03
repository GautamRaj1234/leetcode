class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    int n;

    void solve(int row, int col, int diag1, int diag2) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        int available = ((1 << n) - 1) & ~(col | diag1 | diag2);

        while (available) {
            int bit = available & -available;
            available -= bit;

            int c = __builtin_ctz(bit);

            board[row][c] = 'Q';

            solve(row + 1,
                  col | bit,
                  (diag1 | bit) << 1,
                  (diag2 | bit) >> 1);

            board[row][c] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board.assign(n, string(n, '.'));

        solve(0, 0, 0, 0);

        return ans;
    }
};