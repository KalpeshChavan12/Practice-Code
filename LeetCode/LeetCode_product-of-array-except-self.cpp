//  https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan-v2&envId=leetcode-75
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out(nums.size(), 1);
        int lp = 1, rp=1;
        int N=nums.size();
        for(int i=0; i<N; i++)
        {
            out[i] = lp * out[i];
            out[N-i-1] = rp * out[N-i-1];
            lp *= nums[i];
            rp *= nums[N-i-1];
        }

        return out;
    }
};
