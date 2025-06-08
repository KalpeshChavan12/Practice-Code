// https://neetcode.io/problems/subsets?list=blind75

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1, vector<int>());
        vector<int> prev;
        subsets(nums, 0, res, prev);
        return res;
    }

    void subsets(vector<int>& nums, int index, vector<vector<int>>& res, vector<int> prev) {
        if(index >= nums.size())
        {
            return;
        }

        auto tmp = prev;
        tmp.push_back(nums[index]);
        res.push_back(tmp);

        subsets(nums, index+1, res, tmp);
        subsets(nums, index+1, res, prev);
    }
};
