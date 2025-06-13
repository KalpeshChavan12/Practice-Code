// https://neetcode.io/problems/reverse-integer?list=blind75

class Solution {
public:
    int reverse(int x) {
        int tmp = x;
        int res=0;
        while(tmp)
        {
            int d = tmp % 10;
            if(res > (INT_MAX/10) || res == (INT_MAX / 10) && (d > INT_MAX % 10)) //overflow
                return 0;
            if((res < INT_MIN/10) || res ==  (INT_MIN /10) && (d < INT_MIN %10 ))
                return 0;
            res = (10 * res) + d;
            tmp = tmp / 10;
        }

        return  res;
    }
};
