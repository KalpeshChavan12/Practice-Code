// https://neetcode.io/problems/longest-palindromic-substring?list=blind75

class Solution {
public:
    string longestPalindrome(string s) {
        // odd
        int start = 0;
        int len = 0;

        for(int i=0; i<s.length(); i++)
        {
            int substart = 0, sublen = 0;
            pallen(s, i, i, substart, sublen);
            if(sublen > len)
            {
                len = sublen;
                start = substart;
            }
        }

        for(int i=0; i<s.length()-1; i++)
        {
            int substart = 0, sublen = 0;
            pallen(s, i, i+1, substart, sublen);

            if(sublen > len)
            {
                len = sublen;
                start = substart;
            }
        }

        return s.substr(start, len);
    }

    void pallen(string s, int l, int r, int& start, int& len)
    {
        len = r - l - 1;
        start =  l;
        while(l>=0 && r < s.length())
        {
            if(s[l] != s[r])
                break;
            l--;
            r++;
        }
        
        len = r - l - 1;
        start = l + 1;
    }
};
