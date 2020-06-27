/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){   
    struct ListNode* p;
    struct ListNode* p_next;
    int len = 0;
    int index;
    
    p = head;
    while(p != NULL) {
        p = p->next;
        len++;
    }
    
    index = len - n - 1;
    p = head;
    for(int i=0; i<index; i++) {
        p = p->next;
    }
    
    if(index < 0) {
        p_next = head;
        head = head->next;
        free(p_next);
    } else if(p->next != NULL) {
        p_next = p->next;
        p->next = p_next->next;
        free(p_next);
    }
    
    return head;
}
