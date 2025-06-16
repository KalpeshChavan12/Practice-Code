// https://neetcode.io/problems/surrounded-regions?list=neetcode150

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int ROW = board.size();
        int COL = board[0].size();
        for(int i=0; i<ROW; i++)
        {
            if(board[i][0] == 'O')
                q.push({i, 0});
            if(board[i][COL-1] == 'O')
                q.push({i, COL-1});
        }

        for(int i=0; i<COL; i++)
        {
            if(board[0][i] == 'O')
                q.push({0, i});
            if(board[ROW-1][i] == 'O')
                q.push({ROW-1, i});
        }

        vector<pair<int,int>> dirs = {{1,0}, {-1, 0}, {0, 1},{0, -1}};

        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            board[p.first][p.second] = '*';
            for(auto& d: dirs)
            {
                int r1 = d.first + p. first;
                int c1 = d.second + p.second;

                if(r1 < 0 || c1 <0 || r1 >=ROW || c1 >= COL)
                    continue;
                if(board[r1][c1] == 'X' || board[r1][c1] == '*')
                    continue;
                board[r1][c1] = '*';
                q.push({r1, c1});
            }
        }

        for(int i=0; i< ROW; i++)
        {
             for(int j=0; j<COL; j++)
             {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
             }
        }
        for(int i=0; i< ROW; i++)
        {
             for(int j=0; j<COL; j++)
             {
                if(board[i][j] == '*')
                    board[i][j] = 'O';
             }
        }
    }
};
