/*

https://leetcode.com/problems/generate-parentheses/description/?envType=problem-list-v2&envId=dynamic-programming

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> res;
        int open = n;
        int close =n;
        genP("", open, close, res);

        return res;
    }

    void genP(const string& s, int open , int close, vector<string>& res)
    {
        if(open  == 0 && close == 0)
        {
            res.push_back(s);
            return;
        }

        if(open > 0)
        {
            genP(s + "(", open -1, close, res);
        }
        if(close > open)
        {
            genP(s + ")", open, close -1, res);
        }
    }
};
