/*
A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
 
    Node *slow=head, *fast=head;
    
    while(slow && fast){
        slow = slow->next;
        fast = fast->next;
        if(fast)
            fast=fast->next;
        else
            return false;
        if((slow == fast) )
            return true;
        
        
    }
    
    return false;
}
