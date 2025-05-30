// https://leetcode.com/problems/minimum-path-sum/description

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> minSum(m, vector<int>(n, -1));

        minSum[0][0] = grid[0][0];

       return minPathSum(grid, m-1,  n-1, minSum);
    }

    int minPathSum(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& minSum)
    {
        if(n < 0 || m < 0 )
        {
            return INT_MAX;
        }

        if(minSum[m][n] != -1)
        {
            return minSum[m][n];
        }

        int sum = grid[m][n] + min(minPathSum(grid, m-1, n, minSum), minPathSum(grid, m, n-1,minSum));

        minSum[m][n] = sum;

        return sum;
    }
};
