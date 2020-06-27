/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* p = head;
    int tmp_val;
    
    while(p != NULL && p->next != NULL) {
        tmp_val = p->val;
        p->val = p->next->val;
        p->next->val = tmp_val;
        
        // next pair
        p = p->next->next;
    }
    
    return head;
}
