// https://neetcode.io/problems/longest-increasing-subsequence?list=blind75

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        int res = 1;

        for(int i=0; i<nums.size(); i++)
        {
            res = max(res, lengthOfLIS(nums, i, dp));
        }

        return res;
    }
    int lengthOfLIS(vector<int>& nums, int n, vector<int>& dp)
    {
        if(n == nums.size())
            return 1;
        if(n == nums.size() -1)
        {
             return 1;
        }   
        if(dp[n] != -1)
            return dp[n];
        
        int res = 1;

        for(int i =n+1; i<nums.size(); i++)
        {
            if(nums[n] < nums[i])
            {
                res = max(res, 1 + lengthOfLIS(nums, i, dp));
            }
        }

        dp[n] = res;
        return res;
    }
};
