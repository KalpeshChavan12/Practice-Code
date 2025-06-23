// https://leetcode.com/problems/reverse-vowels-of-a-string/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    string reverseVowels(string s) {
        int l=0, r = s.length()-1;

        while(l<r)
        {
            if(isVowel(s[l]) && isVowel(s[r]))
            {
                char tmp = s[l];
                s[l] = s[r];
                s[r] = tmp;
                l++;
                r--;
                continue;
            }
            
            if(!isVowel(s[l]))
                l++;
            if(!isVowel(s[r]))
                r--;
        }

        return s;
    }

    bool isVowel(char c)
    {
        if( c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' )
            return true;
        return false;
    }
};
