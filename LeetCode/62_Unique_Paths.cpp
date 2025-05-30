// https://leetcode.com/problems/unique-paths/description/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ways(m, vector<int>(n, -1));
        ways[0][0] = 1;
        return uniquePaths1(m-1, n-1, ways);
    }

    int uniquePaths1(int m, int n, vector<vector<int>>& ways)
    {
        if(m < 0 || n < 0)
           return 0;
        
        if(ways[m][n] != -1)
          return ways[m][n];

        int w = uniquePaths1(m-1, n, ways) + uniquePaths1(m, n-1, ways);
        ways[m][n] = w;
        return w;
    }
};
