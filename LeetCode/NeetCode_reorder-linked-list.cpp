// https://neetcode.io/problems/reorder-linked-list?list=blind75

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
    void reorderList(ListNode* head) {
        ListNode *f=head, *s=head, *sp;

        if(!head || !head->next)
            return;

        while(f && s)
        {
            sp = s;
            s=s->next;
            if(f->next)
            {
                f = f->next->next;
            }
            else
                break;
        }

        ListNode* mid =s;

        cout<<"mid "<<mid->val;

        sp->next=NULL;

        mid = revList(mid);

        
        ListNode* curr = head, *l1 = head, *l2=mid;

        int i=0;
        while(curr)
        {
            if(!l2)
                break;
            ListNode* tmp = curr->next, *tmp2 = l2->next;
            curr->next =l2;
            l2->next =tmp;
            l2 = tmp2;
            curr =tmp;
        }
    }

    ListNode* revList(ListNode *head)
    {
        ListNode* curr=head, *pre=NULL;

        while(curr)
        {
            ListNode* tmp = curr->next;
            curr->next=pre;
            pre = curr;
            curr=tmp;
        }

        return pre;
    }
};
