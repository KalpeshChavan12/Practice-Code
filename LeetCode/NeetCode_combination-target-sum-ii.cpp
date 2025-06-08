// https://neetcode.io/problems/combination-target-sum-ii?list=blind75

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        cmb(candidates, target, 0, curr, res);
        return res;
    }

    void cmb(vector<int>& candidates, 
    int target, 
    int index, 
    vector<int> curr, 
    vector<vector<int>>& res)
    {
        if(target == 0)
        {
            res.push_back(curr);
            return;
        }
        
        if(target < 0 || index >= candidates.size())
        {
            return;
        }

        curr.push_back(candidates[index]);
        cmb(candidates, target - candidates[index], index+1, curr, res);
        
        while(index < candidates.size() - 1 &&
              candidates[index] ==  candidates[index+1])
        {
            index++;
        }
        
        curr.pop_back();
        cmb(candidates, target, index+1, curr, res);
    }
};
