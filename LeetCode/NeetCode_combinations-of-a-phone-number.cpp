// https://neetcode.io/problems/combinations-of-a-phone-number?list=blind75

class Solution {
    string keytochars[12] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return vector<string>();
        vector<string> res;
        string prev;
        letterCombinations(digits, prev, 0, res);
        return res;
    }

    void letterCombinations(string& digits, string& prev, int index, vector<string>& res)
    {
        if(index >= digits.length())
        {
            res.push_back(prev);
            return;
        }
        
        auto chars = keytochars[digits[index] - '0'];
        for(auto& c: chars)
        {
            prev.push_back(c);
            letterCombinations(digits, prev, index+1, res);
            prev.pop_back();
        }
    }
};
