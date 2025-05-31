// https://neetcode.io/problems/is-palindrome?list=blind75

class Solution {
public:
    bool isPalindrome(string s) {
        int l=0, r=s.length()-1;

        while(l<r)
        {
            if(!isAN(s[l]))
            {
                l++;
                continue;
            }
            if(!isAN(s[r]))
            {
                r--;
                continue;
            }
            char lc= tolower(s[l]);
            char rc = tolower(s[r]);
            
            if(lc != rc)
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    char tolower(char c)
    {
        if(c >= 'A' && c <= 'Z')
        {
            return ('A' - c);
        }
        return 'a' - c;
    }

    bool isAN(char c)
    {
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
        || (c >= '0' && c <= '9'))
        {
            return true;
        }
        return false;
    }
};
