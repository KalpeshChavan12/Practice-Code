// https://neetcode.io/problems/palindrome-partitioning?list=blind75 

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        partition(s, 0, res, part);
        return res;
    }

    void partition(string s, int i, vector<vector<string>>& res, vector<string>& part)
    {
        if( i >=s.length())
        {
            res.push_back(part);
            return;
        }

        for(int j=i; j<s.length(); j++)
        {
            if(isPall(s, i, j))
            {
                part.push_back(s.substr(i, j-i+1));
                partition(s, j+1, res, part);
                part.pop_back();
            }
        }
    }

    bool isPall(string& s, int l, int r)
    {
        if(l>r)
            return false;
        while(l<r)
        {
            if(s[l] !=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};
