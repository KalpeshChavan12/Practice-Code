// https://neetcode.io/problems/burst-balloons?list=blind75



class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> nums2(nums.size()+2, 1);

        for(int i=0; i< nums.size(); i++)
            nums2[i+1] = nums[i];
        
        vector<vector<int>> dp(nums2.size()+1, vector<int>(nums2.size()+1, -1));

        return maxCoins(nums2, 1, nums2.size()-2, dp);
    }

    int maxCoins(vector<int>& nums, int l, int r, vector<vector<int>>& dp)
    {
        if(l>r)
            return 0;
        
        if(dp[l][r] != -1)
            return dp[l][r];

        int res=0;

        for(int i=l; i<=r; i++)
        {
            int c = nums[l-1] * nums[i] * nums[r+1];
            c += maxCoins(nums, l, i-1, dp) + maxCoins(nums, i+1, r, dp);

            res = max(res, c);
        }

        dp[l][r] = res;
        return res;
    }
};
