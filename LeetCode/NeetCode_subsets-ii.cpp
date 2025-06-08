// https://neetcode.io/problems/subsets-ii?list=blind75

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res(1, vector<int>());
        vector<int> curr;
        subsetsWithDup(nums, 0, curr, res);

        return res;
    }

    void subsetsWithDup(vector<int>& nums, int index, vector<int> curr, vector<vector<int>>& res)
    {
        if(index >= nums.size())
        {
            return;
        }

        curr.push_back(nums[index]);
        res.push_back(curr);

        subsetsWithDup(nums, index+1, curr, res);

        curr.pop_back();
        while(index < nums.size()-1 && nums[index] == nums[index+1])
        {
            index++;
        }
        subsetsWithDup(nums, index+1, curr, res);

    }
};
