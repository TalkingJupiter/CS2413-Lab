/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    //Edge Case
    if(!head) return NULL; // If head is empty then return zero
    struct ListNode *next = NULL;
    struct ListNode *prev = NULL;

    while(head){ //Keep looping until the head is null
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}



    //Draft Code
    //struct ListNode *prev = NULL;
    //struct ListNode *current = head;
    //struct ListNode *nextNode = NULL;
    //
    //while(current != NULL){
    //    nextNode = current->next;
    //    current->next = prev;
    //    prev = current;
    //    current = nextNode;
    //}
    //free(current);
    //free(nextNode);
    //return prev;
