/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(NULLptr) {}
 *     ListNode(int x) : val(x), next(NULLptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        
        int last = lists.size() - 1;
        
        while(last != 0)
        {
            int start = 0;
            while(start <  last)
            {
                lists[start] = MergeTwoList(lists[start], lists[last]);
                start++;
                last--;
            }
        }

        return lists[0];
        
    }
    
    ListNode* MergeTwoList(ListNode* l1, ListNode* l2)
    {
        ListNode* head = NULL, *hp = NULL;
        if (l1 == NULL && l2 == NULL)
            return NULL;
        if (l1 == NULL && l2 != NULL)
            return l2;
        if (l1 != NULL && l2 == NULL)
            return l1;

        ListNode* p1 = l1;
        ListNode* p2 = l2, *tmp = NULL;
        while (p1 != NULL && p2 != NULL)
        {
            
            if (p1->val < p2->val)
            {
                if (head == NULL)
                {
                    head = p1;
                    hp = head;
					p1 = p1->next;
                }
				else
				{
					tmp = p1->next;
					hp->next = p1;
					p1 = tmp;
                    hp = hp->next;
				}
            }
            else
            {
                if (head == NULL)
                {
                    head = p2;
                    hp = head;
                }
				else
				{
					tmp = p2->next;
					hp->next = p2;
					p2 = tmp;
                    hp = hp->next;
				}
            }        
        }

        if (p1 == NULL)
        {
            hp->next = p2;
        }

        if (p2 == NULL)
        {
            hp->next = p1;
        }

        return head;
    }
};
