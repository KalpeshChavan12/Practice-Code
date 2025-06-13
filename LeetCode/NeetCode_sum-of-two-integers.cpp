// https://neetcode.io/problems/sum-of-two-integers?list=blind75

class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        int len = sizeof(int) *8;
        int carry = 0;
        for(int i=0; i<len; i++)
        {
            int a1 = (a>>i) & 1, b1 = (b>>i) & 1;
            int r1 = a1 ^ b1 ^ carry;

            res |= (r1)<<i;
            carry = (a1 & carry) | (b1 & carry) | (a1 & b1);
            
        }

        return res;
    }
};
