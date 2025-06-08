// https://neetcode.io/problems/combination-target-sum?list=blind75

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        vector<vector<int>> res;
        combinationSum(nums, target, curr, 0, res);
        return res;
    }

    void combinationSum(vector<int>& nums,
     int target,
     vector<int>& curr, 
     int index,
    vector<vector<int>> & res)
    {
        if(target == 0)
        {
            res.push_back(curr);
            return;
        }

        if(index >= nums.size() || target < 0)
        {
            return;
        }

        curr.push_back(nums[index]);
        combinationSum(nums, target-nums[index], curr, index, res);
        curr.pop_back();
        combinationSum(nums, target, curr, index+1, res);
    }

};
