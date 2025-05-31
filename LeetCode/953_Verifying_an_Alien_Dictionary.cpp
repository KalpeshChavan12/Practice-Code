// https://leetcode.com/problems/verifying-an-alien-dictionary/description/

class Solution {
public:
    int w[26] = {0};
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0; i< order.length(); i++)
        {
            w[order[i] -'a'] = i; 
        }

        for(int i=0; i< order.length(); i++)
        {
            cout<<w[i]<<" ";
        }

        for(int i=0; i< words.size() - 1; i++)
        {
            if(astrcmp(words[i], words[i+1]) > 0)
            {
                 return false;
            } 
        }

        return true;
    }

    int astrcmp(const string& s1, const string& s2)
    {
        auto l1 = s1.length();
        auto l2 = s2.length();
        int len = min(l1, l2); 
        for(int i=0; i< len; i++)
        {
            if(s1[i] != s2[i])
                return w[s1[i] - 'a'] - w[s2[i] - 'a'];
        }

        return l1 - l2;
    }
};
