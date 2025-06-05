// https://leetcode.com/problems/minimum-window-substring/


class Solution {
public:
    string minWindow(string s, string t) {
        int sCount[256]={0};
        int tCount[256]={0};

        int tlen = t.length();

        if(s.length() < tlen)
        {
            return "";
        }

        for(auto& c: t)
        {
            tCount[c]++;
        }

        int l =0, r=0;
        int len=INT_MAX;
        int start = 0;

        
        for(int r=0; r<s.length(); r++)
        {
            sCount[s[r]]++;

            auto b = isSub(tCount, sCount);
           
            while(b)
            {
                if(r -l+1 < len )
                {
                    start = l;
                    len = r -l+1;
                }

                sCount[s[l]]--;

                b = isSub(tCount, sCount);
                l++;
            }
        }

        if(len == INT_MAX)
            return "";

        return s.substr(start, len);
    }


    bool isSub(int *c1, int *c2)
    {
        for(int i=0; i<256; i++)
        {
            if(c1[i] != 0 && c1[i] > c2[i])
                return false;
        }

        return true;
    }

};
