// https://neetcode.io/problems/anagram-groups

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> res;

        for(auto& s: strs)
        {
            auto k = getA(s);
            auto it = res.find(k);
            if(it == res.end())
            {
                vector<string> tmp;
                tmp.push_back(s);
                res[k] = tmp;
            }
            else
            {
                it->second.push_back(s);
            }
        }

        vector<vector<string>> r;
        
        for(auto kv: res)
        {
            r.push_back(kv.second);
        }

        return r;
    }

    string getA(string s)
    {
        int c1[26] = {0};

        for(auto c: s)
        {
            c1[c-'a']++;
        }

        string r;
        stringstream ss;
        for(int i=0; i< 26; i++ )
        {
            if(c1[i] != 0);
                ss<<(c1[i] +'a')<<('1' + i);
        }
        ss>>r;
        return r;
    }
};
