// https://neetcode.io/problems/find-duplicate-integer?list=blind75

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        if(nums.size() <2)
            return 0;
        int s1=0, s2=0, f=0;

        while(true)
        {
            s1 = nums[s1];
            f = nums[nums[f]];
            if(s1 == f)
            {
                break;
            }
        }

        while(true)
        {
            s1=nums[s1];
            s2=nums[s2];
            if(s1 == s2)
            {
                return s1;
            }
        }

        return 0;
    }
};
