// https://neetcode.io/problems/islands-and-treasure?list=blind75

class Solution {
    int INF;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        bfs(grid);
        
    }

    void bfs(vector<vector<int>>& grid)
    {
        //vector<vector<int>>& visited(grid.size(), vector<int>(grid[0].size(), 0));
        queue<pair<int, int>> q;

        for(int i=0; i< grid.size(); i++)
        {
            for(int j=0; j< grid[0].size(); j++)
                if(grid[i][j] ==0)
                    q.push({i, j});
        }
        

        int level = 0;
        vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, 1},{0, -1}};
        while(!q.empty())
        {
           auto p = q.front();
           q.pop();

            for(auto d: dirs)
            {
                auto r1 = p.first + d.first;
                auto c1 = p.second + d.second;
                if(r1 < 0 || c1 <0 || r1 >= grid.size() || c1 >= grid[0].size())
                    continue;
                if(grid[r1][c1] != INT_MAX)
                    continue;
                
                grid[r1][c1] = 1 +grid[p.first][p.second];
                q.push({r1, c1});
            }
        }
    }

    
};
