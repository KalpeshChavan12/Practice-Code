// https://leetcode.com/problems/jump-game-ii/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return jump1(nums, 0, dp);   
    }

    int jump1(vector<int>& num, int i, vector<int>& dp)
    {
        int size = num.size();
        if(i >= size - 1 )
        {
            return 0;
        }

        if(num[i] == 0)
        {
            return INT_MAX;
        }

        if(dp[i] != -1)
        {
            return dp[i];
        }

        int minJump = INT_MAX;

        for(int j=1; j<= num[i]; j++)
        {
            int tmp = jump1(num, i+j, dp);
            if(tmp != INT_MAX)
            {
                tmp = 1 + tmp;
            }
            if(minJump > tmp)
            {
                minJump = tmp;
            }
        }

        dp[i] = minJump;
        return minJump;
    }
};
