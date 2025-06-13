// https://neetcode.io/problems/max-area-of-island?list=blind75

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> v(grid.size(), vector<bool>(grid[0].size(), false));

        int maxArea=0;

        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(!v[i][j] && grid[i][j] == 1)
                {
                    int res=0;
                    maxAreaOfIsland(grid, v, i, j, res);
                    maxArea = max(maxArea, res);
                }
            }
        }

        return maxArea;
    }

    void maxAreaOfIsland(vector<vector<int>>& grid, vector<vector<bool>>& v, int i, int j, int& res)
    {
        if(i<0 || j < 0 || i >=grid.size()|| j >= grid[0].size())
            return;
        if(v[i][j])
            return;
        if(grid[i][j] == 0)
            return;
        
        res++;
        v[i][j] = true;

        maxAreaOfIsland(grid, v, i+1, j, res);
        maxAreaOfIsland(grid, v, i-1, j, res);
        maxAreaOfIsland(grid, v, i, j+1, res);
        maxAreaOfIsland(grid, v, i, j-1, res);
    }
};
