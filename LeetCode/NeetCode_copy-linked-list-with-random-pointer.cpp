// https://neetcode.io/problems/copy-linked-list-with-random-pointer?list=blind75

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr=head, *h=NULL, *prev = NULL, *curr1=NULL;
        map<Node*, Node*> m;

        while(curr)
        {
            Node *t = new Node(curr->val);
            if(!h)
            {
                h = t;
            }
            if(prev)
            {
                prev->next = t;
            }
            prev = t;
            m[curr] = t;
            curr = curr->next;
        }

        curr = h, curr1 = head;
        while(curr || curr1)
        {
            if(!curr->random)
            {
                auto it = m.find(curr1->random);
                if(it != m.end())
                {
                    curr->random = it->second;
                }
            }
            curr1 = curr1->next;
            curr = curr->next;
        }

        return h;
    }
};
