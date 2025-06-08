// https://neetcode.io/problems/search-for-word-ii?list=blind75


struct TrieNode
{
    vector<TrieNode*> children;
    TrieNode():children(26, NULL), index(-1), word(false) {
    }
    bool word;
    int index;
};

struct Dict
{
    TrieNode* root;
    Dict()
    {
        root = new TrieNode();
    }

    void add(const string& word, int index)
    {
        TrieNode *curr = root;
        for(auto& c: word)
        {
            TrieNode* tmp = curr->children[c - 'a'];
            if(!tmp)
            {
                tmp = new TrieNode();
                curr->children[c - 'a'] = tmp;
            }
            curr = tmp;
        }
        curr->word = true;
        curr->index = index;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Dict d;
        vector<string> res;
        set<int> ires;

        for(int i=0; i<words.size(); i++)
        {
            d.add(words[i], i);
        }  
        
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(),0));
                findW(board, i, j, d.root, visited, ires);
            }
        }

        for(auto& i: ires)
        {
            //cout<<" "<<i<<endl;
            res.push_back(words[i]);
        }

        return res;
    }

    void findW(vector<vector<char>>& board,
     int i,
     int j,
     TrieNode* curr,
     vector<vector<bool>>& visited,
     set<int>& res)
    {
        if(i<0 || j<0 || i >= board.size() || j >=board[0].size())
            return;
        
        if(!curr)
        {
            return;
        }
        
        if(visited[i][j])
            return;

        auto c = board[i][j];
        auto& tnode = curr->children[c - 'a'];
        if(!tnode)
        {
            return;
        }

        visited[i][j] = true;
        if(tnode->word)
            res.insert(tnode->index);
        
        findW(board, i+1, j, tnode, visited, res);
        findW(board, i-1, j, tnode, visited, res);
        findW(board, i, j+1, tnode, visited, res);
        findW(board, i, j-1, tnode, visited, res);

        visited[i][j] = false;
    }
};
