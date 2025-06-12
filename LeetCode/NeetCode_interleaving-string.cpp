// https://neetcode.io/problems/interleaving-string?list=blind75

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        string s4 = s1 + s2;

        if(s4.length() != s3.length())
            return false;

        vector<vector<int>> dp(s3.length()+1, vector<int>(s4.length()+1, -1));
        dp[0][0] = 1;
        return solve(s1, s2, s3, s1.length(), s2.length(), dp);
    }

    bool solve(string& s1, string& s2, string& s3, int l1, int l2, vector<vector<int>>& dp )
    {
        if(l1 == 0 && l2 == 0)
            return true;
        
        if(dp[l1][l2] != -1)
            return dp[l1][l2];

        bool res = false;

        if(l1 > 0 && s1[l1-1] == s3[l1+l2-1])
        {
            res = res || solve(s1, s2, s3, l1-1, l2, dp);
        }
        if(l2 > 0 && s2[l2-1] == s3[l1+l2-1])
        {
            res = res || solve(s1, s2, s3, l1, l2-1, dp);
        }
        
        dp[l1][l2] =res;
        return res;
    }
};
