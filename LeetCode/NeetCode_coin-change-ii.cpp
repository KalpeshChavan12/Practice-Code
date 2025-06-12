// https://neetcode.io/problems/coin-change-ii?list=blind75

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        return change(amount, coins.size()-1, coins, dp);
    }

    int change(int amount, int n, vector<int>& coins, vector<vector<int>> & dp)
    {
        if(amount < 0)
            return 0;
        if(amount == 0)
            return 1;
        if(n <0)
            return 0;
        
        if(dp[n][amount] != -1)
        {
            return dp[n][amount];
        }

        int res = change(amount - coins[n], n, coins, dp) + change(amount, n - 1, coins, dp);
        
        dp[n][amount] = res;
        
        return res;
    }
};
