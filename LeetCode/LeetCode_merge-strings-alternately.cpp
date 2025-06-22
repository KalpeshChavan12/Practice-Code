// https://leetcode.com/problems/merge-strings-alternately/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i1 =0, i2=0;
        string res;
        while(i1 < word1.length() || i2 < word2.length())
        {
            if(i1 < word1.length())
            {
                res.push_back(word1[i1]);
                i1++;
            }
            if(i2 < word2.length())
            {
                res.push_back(word2[i2]);
                i2++;
            }
        }

        return res;
    }
};
