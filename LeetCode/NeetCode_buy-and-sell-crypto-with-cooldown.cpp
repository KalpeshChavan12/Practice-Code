// https://neetcode.io/problems/buy-and-sell-crypto-with-cooldown?list=blind75

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(prices.size()+1, 0));

        return maxProfit(prices, 1, 0, dp);
        
    }
    int maxProfit(vector<int>& prices, int buy, int n, vector<vector<int>>& dp)
    {
        if(n >= prices.size())
            return 0;

        if(dp[buy][n] != 0)
        {
            return dp[buy][n];
        }
        
        int cooldown = maxProfit(prices, buy, n+1, dp);
        if(buy)
        {
            int _buy = maxProfit(prices, 0, n+1, dp) - prices[n];
            dp[buy][n] = max(_buy, cooldown);
        }
        else
        {

            int sell = maxProfit(prices, 1, n+2, dp) + prices[n];
            dp[buy][n] = max(sell, cooldown);
        }

        return dp[buy][n];
    }
};
