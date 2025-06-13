// https://neetcode.io/problems/missing-number?list=blind75

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        int sum = (n * (n+1)) / 2;
        for(auto i: nums)
        {
            res+=i;
        }

        return sum - res;
    }
};
