// https://neetcode.io/problems/number-of-one-bits?list=blind75

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int len = sizeof(uint32_t) * 8;
        int res = 0;
        for(int i = 0; i< len; i++)
        {
            res += ((n & (1<<i)) ?  1 : 0);
        }

        return res;
    }
};
