// https://neetcode.io/problems/word-break?list=blind75

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length()+1, -1);
        return wordBreak(s, wordDict, 0, dp);
    }

    bool wordBreak(string s, vector<string>& wordDict, int n, vector<int>& dp) {
        if(n == s.length())
        {
            return true;
        }
        if(n > s.length())
        {
            return false;
        }

        if(dp[n] != -1)
        {
            return dp[n];
        }

        int res = false;

        for(auto& w: wordDict)
        {
            if(matched(s, n ,w))
            {
                res |= wordBreak(s, wordDict, n+w.length(), dp);
            }
        }
        dp[n] = res;
        return res;
    }

    bool matched(string& s1, int l, string& s2)
    {
        for(int i=0; i<s2.length(); i++)
        {
            if(i+l >= s1.length())
                return false;
            if(s1[i+l] != s2[i] )
                return false;
        }
        return true;
    }
};
