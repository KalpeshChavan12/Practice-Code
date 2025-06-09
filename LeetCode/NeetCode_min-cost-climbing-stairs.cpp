// https://neetcode.io/problems/min-cost-climbing-stairs?list=blind75

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, -1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        minCostClimbingStairs(cost, cost.size()-1, dp);
        return min(dp[cost.size()-2], dp[cost.size()-1]);
    }
    int minCostClimbingStairs(vector<int>& cost, int i,  vector<int>& dp) {
        if(i < 0)
            return INT_MAX;
        if( i <= 1)
            return cost[i];
        if(dp[i] != -1)
            return dp[i];

        int res =  cost[i]+ min(minCostClimbingStairs(cost, i-1, dp),  minCostClimbingStairs(cost, i-2, dp));
        dp[i] =res;
        return res;
    }
};
