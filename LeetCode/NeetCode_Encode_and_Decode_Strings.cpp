// https://neetcode.io/problems/string-encode-and-decode?list=blind75

class Solution {
public:

    string encode(vector<string>& strs) {
        stringstream ss;
        for(auto& s: strs)
        {
            ss<<s.length()<<'#'<<s;
        }

        return ss.str();
    }

    vector<string> decode(string s) {
        int i=0;
        int l = s.length();
        int num = 0;
        vector<string> res;
        while(i<l)
        {
            if(s[i] != '#')
            {
                num = 10 * num + s[i]-'0';
                i++;
            }
            else
            {
                res.push_back(s.substr(i+1, num));
                i=i+1+num;
                num=0;
            }
        }

        return res;
    }
};
