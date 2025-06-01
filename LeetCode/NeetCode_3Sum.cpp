// 3 https://neetcode.io/problems/three-integer-sum?list=blind75

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for(int i=0; i<nums.size()-1; i++)
        {
            auto l = i+1;
            auto r = nums.size() -1;
            
            if(i>0 && nums[i] == nums[i-1])
                continue;

            while(l<r)
            {
                if(nums[i] + nums[l]+ nums[r] == 0)
                {
                    vector<int> rr{nums[i],nums[l], nums[r]};
                    res.push_back(rr);
                    l=l+1;
                    while((nums[l] ==nums[l-1]) && l < r )
                    {
                        l++;
                    }
                }
                if(nums[i] + nums[l]+ nums[r] < 0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return res;
    }
};
