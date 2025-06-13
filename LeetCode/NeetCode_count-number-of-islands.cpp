// https://neetcode.io/problems/count-number-of-islands?list=blind75

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    visit(grid, i, j, visited);
                    res++;
                }
            }
        }

        return res;
    }

    void visit(vector<vector<char>>& grid,int i, int j, vector<vector<int>>& visited)
    {
        if(i<0 || j < 0 || i>=grid.size() || j >= grid[0].size())
            return;
        
        if(visited[i][j])
            return;
        
        if(grid[i][j] != '1')
            return;
        
        visited[i][j] = 1;

        visit(grid, i-1, j, visited);
        visit(grid, i+1, j, visited);
        visit(grid, i, j-1, visited);
        visit(grid, i, j+1, visited);
    }
};
