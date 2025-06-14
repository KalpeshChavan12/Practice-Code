// https://neetcode.io/problems/rotting-fruit?list=blind75
// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();

        vector<vector<int>> result(ROW, vector<int>(COL, -1));

        queue<pair<int, int>> q;

        for(int i=0; i<ROW; i++)
        {
            for(int j=0; j< COL; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                    result[i][j] = 0;
                }  
            }
        }

        vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, 1},{0, -1}};
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int _row = p.first;
            int _col = p.second;

            for(auto& d: dirs)
            {
                int r1 = _row + d.first, c1 = _col + d.second;

                if(r1< 0 || c1<0 || r1 >= ROW || c1 >= COL 
                    || result[r1][c1] != -1 || grid[r1][c1] == 0)
                    continue;
                
                result[r1][c1] = 1+ result[_row][_col];
                cout<<result[r1][c1]<<endl;
                q.push({r1, c1});
            } 
        }

        int maxR = 0;
        for(int i=0; i<ROW; i++)
        {
            for(int j=0; j< COL; j++)
            {
                if(grid[i][j] == 1 && result[i][j] == -1)
                    return -1;
                if(grid[i][j] == 1)
                    maxR = max(result[i][j], maxR);
            }
        }

        return maxR;
    }
};
