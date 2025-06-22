// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int _max = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        for(auto c: candies)
        {
            res.push_back( c + extraCandies >= _max);
        }

        return res;
    }
};
