// https://neetcode.io/problems/house-robber?list=blind75

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return rob2(nums, nums.size()-1, dp);
    }

    int rob2(vector<int>& nums, int n, vector<int>& dp)
    {
        if(n<0)
            return 0;
        if(n == 0)
            return nums[0];
        
        if(dp[n] != -1)
            return dp[n];
        dp[n] = max(nums[n] + rob2(nums, n-2, dp),rob2(nums, n-1, dp));
        
        return dp[n];
    }
};
