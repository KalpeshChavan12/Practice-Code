// https://neetcode.io/problems/edit-distance?list=blind75

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();

        vector<vector<int>> dp(l1+1, vector<int>(l2+1, -1));
        int l = lcs2(word1, word2, l1, l2, dp);

        return l;
 
    }

    int lcs2(string& word1, string& word2, int l1, int l2, vector<vector<int>>& dp)
    {
        if(l1 == 0 && l2 == 0)
            return 0;
        if(l1 == 1 && l2 == 1)
        {
            return word1[l1-1] == word2[l2-1] ? 0 : 1;
        }

        if(l2 == 0)
            return l1;
        if(l1 == 0)
            return l2;
        
        if(dp[l1][l2] != -1)
            return dp[l1][l2];
        
        int res = 0;
        if(word1[l1-1]  == word2[l2-1])
        {
            res = lcs2(word1, word2, l1-1, l2-1, dp);
        }
        else
        {
            int dp1 = 1+lcs2(word1, word2, l1 -1, l2, dp);
            int dp2 = 1+lcs2(word1, word2, l1 -1, l2-1, dp);
            int dp3 = 1+ lcs2(word1, word2, l1, l2-1, dp);
            res = min(dp1, min(dp2, dp3));
        }

        dp[l1][l2] =res;

        return res;
    }

};
