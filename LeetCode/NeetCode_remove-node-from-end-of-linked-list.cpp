// https://neetcode.io/problems/remove-node-from-end-of-linked-list?list=blind75

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode* pre=NULL, *f=head, *s=head;

        if(!head)
            return head;
        
        int i=0;
        while(f->next)
        {
            f = f->next;
            i++;
            if(i<n)
            {
                continue;
            }
            pre = s;
            s = s->next;
        }

        if(!pre)
        {
            head=head->next;
            return head;
        }
 
        pre->next = s->next;
        return head;
    }
};
