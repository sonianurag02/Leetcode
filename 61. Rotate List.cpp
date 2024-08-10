// --------------------------- Approach - 1 --------------------------------

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* ptr = head;
        ListNode* prev;
        int count = 0;

        while(ptr){
            ptr = ptr->next;
            count++;
        }

        int i = 0;
        while(i < (k % count)){
            ptr = head;
            prev = NULL;
            while(ptr->next != NULL){
                prev = ptr;
                ptr = ptr->next;
            }

            dummy->next = ptr;
            ptr->next = head;
            head = ptr;
            prev->next = NULL;

            i++;
        }

        return dummy->next;
    }
};