// https://neetcode.io/problems/maximum-product-subarray?list=blind75

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];

        int currMin = 1, currMax=1, res = nums[0];

        for(int i=0; i<nums.size(); i++)
        {
            int tmp = currMax * nums[i];
            currMax = _max(nums[i], currMax * nums[i], currMin * nums[i]);
            currMin = _min(nums[i], tmp, currMin * nums[i]);
            res = max(res, currMax);
        }

        return res;
    }

    int _max(int i, int j, int k)
    {
        return max(i, max(j,k));
    }

    int _min(int i, int j, int k)
    {
        return min(i, min(j,k));
    }
};
