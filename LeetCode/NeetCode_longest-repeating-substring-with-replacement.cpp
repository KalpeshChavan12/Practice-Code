// https://neetcode.io/problems/longest-repeating-substring-with-replacement?list=blind75

class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> count;

        int l=0, r=0;
        int maxw =0;
        int res=0;

        for(int r=0; r<s.size(); r++)
        {
            count[s[r]]++;

            maxw = max(maxw, count[s[r]]);

            while((r-l+1) - maxw > k)
            {
                count[s[l]]--;
                l++;
            }

            res=max(res, r-l+1);
        }
        
        return res;
    }
};


