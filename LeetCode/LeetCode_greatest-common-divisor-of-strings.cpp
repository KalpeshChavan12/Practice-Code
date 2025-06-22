// https://leetcode.com/problems/greatest-common-divisor-of-strings/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if((str1+str2) != (str2 + str1))
        {
            return "";
        } 

        int _gcd = gcd(str1.length(), str2.length());

        return str1.substr(0, _gcd);
    }
};
