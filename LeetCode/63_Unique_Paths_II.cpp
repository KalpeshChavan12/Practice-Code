// https://leetcode.com/problems/unique-paths-ii/description/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size(); 
        
        vector<vector<int>> ways(m, vector<int>(n, -1));
        ways[0][0] = 1;

        return uniquePathsWithObstacles(obstacleGrid, m -1, n-1, ways);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<int>>& ways) {

        if(m < 0 || n < 0)
        {
            return 0;
        }

        if(obstacleGrid[m][n] == 1)
        {
            ways[m][n] = 0;
            return 0;
        }

        if(ways[m][n] != -1)
        {
            return ways[m][n];
        }

        int w = uniquePathsWithObstacles(obstacleGrid, m -1, n, ways) 
            + uniquePathsWithObstacles(obstacleGrid, m, n-1, ways);

        ways[m][n] = w;

        return w;
    }
};
