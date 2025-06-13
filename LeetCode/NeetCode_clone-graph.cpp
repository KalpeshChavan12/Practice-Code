// https://neetcode.io/problems/clone-graph?list=blind75

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> oldNewMap;

        return cloneGraph(node, oldNewMap);
    }

    Node* cloneGraph(Node* node, map<Node*, Node*>& oldNewMap)
    {
        if(!node)
            return node;
        
        if(oldNewMap.find(node) != oldNewMap.end())
            return oldNewMap[node];
        
        if(oldNewMap.find(node) == oldNewMap.end())
        {
            oldNewMap[node] = new Node(node->val);
        }

        for(int i=0; i< node->neighbors.size(); i++)
        {
            if(oldNewMap.find(node->neighbors[i]) == oldNewMap.end())
            {
                auto n = cloneGraph(node->neighbors[i], oldNewMap);
                oldNewMap[node->neighbors[i]] = n;
            } 
            oldNewMap[node]->neighbors.push_back(oldNewMap[node->neighbors[i]]);
        }

        return oldNewMap[node];
    }
};
