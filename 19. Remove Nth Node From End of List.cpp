// -------------------------------- Solution ------------------------------------------

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
        if(head == NULL || (head->next == NULL && n == 1)){
            return NULL;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        int count = 0;
        ListNode* ptr = dummy;
        while(ptr != NULL){
            count++;
            ptr = ptr->next;
        }

        ptr = dummy;
        ListNode* prev = NULL;
        while(ptr != NULL){
            if(count == n){
                prev->next = (ptr->next != NULL) ? ptr->next : NULL;
                break;
            }
            prev = ptr;
            ptr = ptr->next;
            count--;
        }

        return dummy->next;
    }
};