// https://neetcode.io/problems/count-subsequences?list=blind75

class Solution {
public:
    int numDistinct(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, -1));
        return lcs(s,t,l1, l2, dp);
    }
    int lcs(string& s, string& t, int l1, int l2, vector<vector<int>>& dp)
    {
        if(l1 < 0 || l2 < 0)
            return 0;
        
        if(l2 == 0)
        {
            return 1;
        }

        if(l1 == 0)
            return 0;
        
        if(dp[l1][l2] != -1)
            return dp[l1][l2];

        int res = 0;
        if(s[l1-1] ==  t[l2-1])
        {
            res = lcs(s, t, l1-1, l2 -1, dp);
        }
        
        res =  res + lcs(s, t, l1-1, l2, dp);
        
        dp[l1][l2] = res;

        return res;
    }
};
