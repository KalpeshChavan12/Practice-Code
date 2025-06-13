// https://neetcode.io/problems/counting-bits?list=blind75

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0; i<= n; i++)
        {
            res.push_back(bcount(i));
        }

        return res;
    }

    int bcount(int i)
    {
        int len = sizeof(int) * 8;
        int res = 0;
        for(int j=0; j<len; j++)
        {   
            res += ( i & (1<<j)) ? 1 : 0;
        }

        return res;
    }
};
