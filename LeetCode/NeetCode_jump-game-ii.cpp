// https://neetcode.io/problems/jump-game-ii?list=neetcode150

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxSofar =0;
        for(int i=0; i< nums.size(); i++)
        {
            if(maxSofar >= i)
            {
                maxSofar = max(maxSofar, nums[i]+i);
            }
        }

        return nums.size()-1 <= maxSofar;
    }
};
