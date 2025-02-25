/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode));  //Allocate the mem for temp pointer
    tmp->next = head; //Point the temp pointer to head of the list

    struct ListNode *current = tmp; //Make a new pointer and point to the head 
    while(current->next != NULL){  //Scan the whole list until the current pointer hits a dead end.
        if(current->next->val == val){       // Check if the value that's pointing is the value that we want to remove from the list
            struct ListNode *deleter = current->next; //
            current->next = current->next->next; // If it is assign the pointer to the next node so we will remove the value that's in the list
            free(deleter);

        }
        else{ // If it's not continue
            current = current->next; 
        }
    }
    return tmp->next; //Return to the head of the list
}
