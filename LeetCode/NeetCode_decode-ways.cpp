// https://neetcode.io/problems/decode-ways?list=blind75

class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0)
            return 0;
        vector<int> dp(s.length()+2, -1);

        return numDecodings(s, 0, dp); 
       
    }
    
    int numDecodings(string& s, int n, vector<int>& dp)
    {
        if(n == s.size())
            return 1;
        
        if(s[n] == '0' )
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        int dp1 = numDecodings(s, n+1, dp);
        int dp2 = 0;
        if(n + 1 < s.size() && s[n] != '0' && ((s[n+1] - '0') + (s[n] -'0') *10) <= 26)
        {
            dp2 = numDecodings(s, n+2, dp);
        }
        
        dp[n] =  dp1+dp2;
        return dp1+dp2;
    }
    
    
};
