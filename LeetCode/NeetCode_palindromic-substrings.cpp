// https://neetcode.io/problems/palindromic-substrings?list=blind75

class Solution {
public:
    int countSubstrings(string s) {
        
        if(s.length() == 0)
            return 0;
        
        int count = 0;

        for(int i=0; i<s.length(); i++)
        {
            count += countPall(s, i, i);
        }

        for(int i=0; i<s.length()-1; i++)
        {
            count += countPall(s, i, i+1);
        }

        return count;
    }

    int countPall(string& s, int l, int r)
    {
        int i=0;

        while(l>=0  && r < s.length())
        {
            if(s[l] != s[r])
                break;
            l--;
            r++;
            i++;
        }

        return i;
    }
};


