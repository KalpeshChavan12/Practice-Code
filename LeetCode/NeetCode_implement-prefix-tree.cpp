// https://neetcode.io/problems/implement-prefix-tree?list=blind75

struct TrieNode
{
    TrieNode* child[26];

    TrieNode(): isWord(false)
    {
        for(int i=0; i<26; i++)
        {
            child[i] = NULL;
        }
    }

    bool isWord;
};

class PrefixTree {
    TrieNode *root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
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
        TrieNode* n=root;
        for(auto& c: word)
        {
            if(!n->child[c - 'a'])
                return false;
            
            n = n->child[c - 'a'];
        }

        return n ? n->isWord : false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* n=root;
        for(auto& c: prefix)
        {
            if(!n->child[c - 'a'])
                return false;
            
            n = n->child[c - 'a'];
        }

        return n != NULL;
    }
};

