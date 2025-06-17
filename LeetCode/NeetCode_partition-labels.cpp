// https://neetcode.io/problems/partition-labels?list=neetcode150

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> high(256 , -1);

        for(int i=0; i< s.length(); i++)
        {
            high[s[i]] = max(high[s[i]], i);
        }

        vector<int> res;

        int i=0;
        while(i<s.length())
        {
            int l=i, h=high[s[i]];
            
            while(l<=h && (h < s.length() && l < s.length()))
            {
                h = max(h, high[s[l]]);
                l++;
            }

            int len = h-i+1;
            res.push_back(len);
            i=l;
        }

        return res;
        
    }
};
