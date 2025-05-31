// https://neetcode.io/problems/longest-consecutive-sequence?list=blind75

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     map<int, int> lc;

     for(int i=0; i<nums.size(); i++)
     {
        lc[nums[i]]=1;
     }

     int m = 0;

     for(int i=0; i<nums.size(); i++)
     {
        auto it = lc.find(nums[i]-1);

        int k=0;
        while(it != lc.end())
        {
            lc[nums[i]] += it->second;
            lc.erase(it);
            k++;
            it = lc.find(nums[i]-1 - k);
        }
     }

     for(auto& i: lc)
     {
        m=max(i.second, m);
     }

     return m;
    }
};
