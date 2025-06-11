// https://neetcode.io/problems/partition-equal-subset-sum?list=blind75

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tsum=0;
        for(auto& i: nums)
            tsum += i;
        if(tsum % 2 ==1)
            return false;
        tsum = tsum / 2;
        vector<vector<int>> dp(nums.size()+1, vector<int>(tsum+1, -1));
        
        return targetSum(nums, nums.size()-1, tsum, dp);
    }

    bool targetSum(vector<int>& nums, int n, int target, vector<vector<int>>& dp)
    {
        if(n < 0)
            return false;
        if(target < 0)
            return 0;
        if(target == 0)
            return true;

        if(dp[n][target] != -1)
            return dp[n][target];

        if(nums[n] > target)
        {
            dp[n][target] = targetSum(nums, n-1, target, dp);
            return dp[n][target];
        }

        dp[n][target] = targetSum(nums, n-1, target - nums[n], dp) || targetSum(nums, n-1, target, dp);
        return dp[n][target];
    }
};
