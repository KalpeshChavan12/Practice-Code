// https://leetcode.com/problems/regular-expression-matching/description/
//
class Solution {
public:
    bool isMatch(string s, string p) {
        auto plen = p.length();
        auto slen = s.length();

        vector<vector<int>> dp(plen+1,vector<int>(slen+1, -1));
        
        if (plen == 0 && slen == 0)
        {
            return true;
        }
        
        return isMatch(s, p, 0, 0, dp);
        
    }

    bool isMatch(string s, string p, int sindex, int pindex, vector<vector<int>>& dp)
    {
        auto plen = p.length();
        auto slen = s.length();
        
        if (sindex >= slen && pindex >= plen)
        {
            dp[pindex][sindex] = 1;
            return true;
        }

        if(pindex >=plen)
        {
            return false;
        }
    
        if( dp[pindex][sindex] != -1)
        {
            return dp[pindex][sindex];
        }
        
        bool matched = sindex < slen && ((s[sindex] == p[pindex]) || p[pindex] == '.');
    
        if (pindex + 1 < plen && p[pindex + 1] == '*')
        {
                dp[pindex][sindex] = isMatch(s, p, sindex, pindex + 2, dp) || (matched && isMatch(s, p, sindex + 1, pindex, dp));
                return dp[pindex][sindex];
        }

        if(matched)
        { 
            dp[pindex][sindex] = isMatch(s, p, sindex+1, pindex+1, dp);
            return dp[pindex][sindex];
        }
        dp[pindex][sindex] = 0;
        return dp[pindex][sindex];
    }
};
