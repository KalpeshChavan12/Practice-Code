// https://neetcode.io/problems/n-queens?list=blind75

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<pair<int, int>> pos;
        NQ(0, n, pos, res);
        return res;
    }

    void NQ(int r, int n, vector<pair<int, int>>& pos, vector<vector<string>>& res)
    {
        if(r >= n)
        {
            res.push_back(toboard(pos, n));
        }

        for(int c=0; c< n; c++)
        {
            if(isSafe(r, c, pos))
            {
                pos.push_back({r, c});
                NQ(r+1, n, pos, res);
                pos.pop_back();
            }
        }
    }

    vector<string> toboard(vector<pair<int, int>>& pos, int n)
    {
        vector<string> b(n, string(n,'.'));
        for(auto& p: pos)
        {
            b[p.first][p.second] = 'Q';
        }

        return b;
    }


    bool isSafe(int i, int j, vector<pair<int, int>>& pos)
    {
        for(auto& p: pos)
        {
            if(i == p.first ||
                j == p.second ||
                abs(i-p.first) == abs(j-p.second))
            {
                return false;    
            }
        }

        return true;
    }
};
