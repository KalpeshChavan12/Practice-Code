// https://neetcode.io/problems/coin-change?list=blind75

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MIN);
        int res = coinChange(coins, amount, dp);
        return res == INT_MAX ? -1 : res;
    }

    int coinChange(vector<int>& coins, int amount, vector<int>& dp)
    {
        if(amount  < 0)
        {
            return INT_MAX;
        }

        if(amount == 0)
            return 0;

        if(dp[amount] != INT_MIN)
        {
            return dp[amount];
        }
        int res = INT_MAX;
        for(auto& c: coins)
        {
            int tmp =  coinChange(coins, amount - c, dp);
            if(tmp != INT_MAX)
            {
                res = min(res, 1+tmp);
            }
        }

        dp[amount] = res;
        return res;
    }
};
