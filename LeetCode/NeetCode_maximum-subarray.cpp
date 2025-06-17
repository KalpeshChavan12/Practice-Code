// https://neetcode.io/problems/maximum-subarray?list=neetcode150

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;
        for(auto i : nums)
        {
            
            currSum = max(i, currSum+i);
            maxSum = max(currSum, maxSum);
        }

        return maxSum;
    }
};
