// https://leetcode.com/problems/wildcard-matching/description/?envType=problem-list-v2&envId=dynamic-programming
class Solution {
public:
    bool isMatch(string s, string p) {
        auto slen = s.length();
        auto plen= p.length();

        vector<vector<int>> dp(plen+1, vector<int>(slen+1, -1));

        return isMatch(s,p, 0,0, dp);
    }
    
    bool isMatch(string s, string p, int sindex, int pindex, vector<vector<int>>& dp)
    {
        auto slen = s.length();
        auto plen = p.length();
        if(sindex >= slen && pindex >= plen)
        {
            return true;
        }

        if(pindex > plen)
        {
            return false;
        }

        if(dp[pindex][sindex] != -1)
        {
            return dp[pindex][sindex];
        }

        bool matched = (sindex < slen) && (s[sindex] == p[pindex] || p[pindex] == '?');

        if(p[pindex] == '*')
        {
            dp[pindex][sindex] = (((sindex < slen) && isMatch(s,p, sindex+1, pindex, dp)) || isMatch(s, p, sindex, pindex+1, dp));
            return dp[pindex][sindex];
        } 

        if(matched)
        {
            dp[pindex][sindex] = isMatch(s, p, sindex+1, pindex+1, dp);
            return dp[pindex][sindex];
        }

         dp[pindex][sindex] = false;
        return dp[pindex][sindex];
    }
};
