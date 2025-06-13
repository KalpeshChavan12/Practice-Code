// https://neetcode.io/problems/reverse-bits?list=blind75

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int len = sizeof(uint32_t) * 8;
        for(int i=0; i<len; i++)
        {
            int tmp = (n & (1<<i)) ? 1 : 0;
            res +=   (tmp<<(len -i-1));
        }
        return res;
    }
};
