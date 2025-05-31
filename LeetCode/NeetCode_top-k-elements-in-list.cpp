// K Frquent element https://neetcode.io/problems/top-k-elements-in-list?list=blind75

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int buckets[2001]={0};

        for(auto& i: nums)
        {
            buckets[i+1000]++;
        }

        int c = 0;
        vector<int> res;
        vector<tuple<int, int>> freq;

        for(int i=2000; i>=0; i--)
        {
            freq.push_back(std::make_tuple(buckets[i],i-1000));
        }

        std::sort(freq.begin(), freq.end(), tcmp);

        for(int i=0; i< k; i++)
        {
            res.push_back(std::get<1>(freq[i]));
        }

        return res;
    }

    static bool tcmp(tuple<int, int> a, tuple<int, int> b)
    {
        return std::get<0>(a) > std::get<0>(b);
    }
};
