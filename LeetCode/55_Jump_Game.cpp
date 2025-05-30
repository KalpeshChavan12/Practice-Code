// https://leetcode.com/problems/jump-game/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return INT_MAX != canJump(nums, 0, dp);
    }

    int canJump(vector<int>& nums, int i, vector<int>& dp)
    {
        int size = nums.size();
        if(i >= size -1)
        {
            return 0;
        }

        if(nums[i] == 0)
        {
            return INT_MAX;
        }

        if(dp[i] != -1)
        {
            return dp[i];
        }

        int minJump = INT_MAX;
        for(int j=nums[i]; j>=1 ; j--)
        {
            int tmp = canJump(nums, i+j, dp);
            if(tmp != INT_MAX)
            {
                tmp = 1 + tmp;
            }
            
            if(minJump > tmp)
            {
                minJump = tmp;
            }

            if(tmp != INT_MAX)
                break;
        }

        dp[i] = minJump;
        return minJump;
    }
};
