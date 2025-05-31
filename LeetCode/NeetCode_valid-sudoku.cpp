// https://neetcode.io/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9, set<char>());
        vector<set<char>> cols(9, set<char>());
        vector<set<char>> grid(9, set<char>());

        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                if(rows[i].find(board[i][j]) != rows[i].end())
                {
                    return false;
                }
                if(cols[j].find(board[i][j]) !=cols[j].end())
                {
                    return false;
                }

                if(grid[((i/3) *3) + (j/3)].find(board[i][j]) != grid[((i/3) *3) + (j/3)].end())
                {
                    return false;
                }
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                grid[((i/3) *3) + (j/3)].insert(board[i][j]);
            }
        }

        return true;
    }
};
