// https://neetcode.io/problems/house-robber-ii?list=blind75

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() ==1)
            return nums[0];
            
        vector<int> num1(nums.begin(), nums.end()-1);
        vector<int> num2(nums.begin()+1, nums.end());
        vector<int> dp1(num1.size()+1, -1);
        vector<int> dp2(num2.size()+1, -1);

        return max(rob(num1, num1.size()-1, dp1), rob(num2, num2.size()-1, dp2));
    }

    int rob(vector<int>& nums, int n, vector<int>& dp)
    {
        if(n <0)
            return 0;
        if(n == 0)
        {   
             dp[n] = nums[0];
             return nums[0];
        }   
        if(nums.size() == 1)
            return nums[0];
        
        if(dp[n] != -1)
            return dp[n];

        dp[n] = max(nums[n] + rob(nums, n-2, dp), rob(nums, n-1, dp));
        return dp[n];
    }
};
