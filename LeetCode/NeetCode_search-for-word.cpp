// https://neetcode.io/problems/search-for-word?list=blind75

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                vector<vector<char>> v(board.size(), vector<char>(board[0].size(), 0));
                if(search(board, i, j, v, word, 0))
                    return true;
            }
        }

        return false;
    }

    bool search(vector<vector<char>>& board, int i, int j, vector<vector<char>>& v, string& word, int wi)
    {
        if(i<0 || j<0 || i >= board.size() || j >= board[0].size())
        {
            return false;
        }

        if(wi >=word.length())
        {
            return false;
        }

        if(v[i][j])
            return false;

        char c = board[i][j];
        if(c != word[wi])
        {
            return false;
        }else if(wi == word.length()-1) {
            return true;
        }

        v[i][j] = true;

        bool res = search(board, i+1, j, v, word, wi+1) ||
                   search(board, i-1, j, v, word, wi+1) ||
                   search(board, i, j-1, v, word, wi+1) ||
                   search(board, i, j+1, v, word, wi+1);

        if(res)
            return res;
        v[i][j] = false;

        return res;
    }
};
