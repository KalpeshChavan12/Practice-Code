// https://leetcode.com/problems/wildcard-matching/description/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    bool isMatch(string s, string p) {
        auto slen = s.length();
        auto plen= p.length();

        vector<vector<int>> dp(plen+1, vector<int>(slen+1, 0));

        dp[0][0] = 1;

        //special case
        for(int i=1; i<=plen; i++)
        {
            if(p[i-1] == '*')
            {
                dp[i][0] = dp[i-1][0];
            }
        }

        for(int i=1; i<= plen; i++)
        {
            for(int j=1; j<= slen; j++)
            {
                if(p[i-1] == '?' || p[i-1] == s[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }

                if(p[i-1] == '*')
                {
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                }
            }
        }

        return dp[plen][slen];
    }
    
    
};
