// https://neetcode.io/problems/design-word-search-data-structure?list=blind75

struct TrieNode
{
    vector<TrieNode*> child;

    TrieNode(): isWord(false), child(26, NULL)
    {
    }

    bool isWord;
};


class WordDictionary {
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node=root;
        for(auto& c: word)
        {
            auto& tmp = node->child[c - 'a'];
            if(!tmp)
            {
                tmp = new TrieNode();
                node->child[c - 'a'] = tmp;
            }
            node = tmp;
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        
        return search(root, word, 0);
    }

    bool search(TrieNode* root, string word, int idx)
    {
        if(!root)
            return false;
        
        TrieNode* curr=root;

        for(int i=idx; i<word.size(); i++)
        {
            auto& c= word[i];

            if(c == '.')
            {
                for(int j=0; j<26; j++)
                {
                    if(curr->child[j] && search(curr->child[j], word, i+1))
                        return true;
                }

                return false;
            }
            else
            {
                if(!curr->child[c - 'a'])
                    return false;
                curr =curr->child[c - 'a'];
            }
        }

        return curr->isWord;
    }
};
