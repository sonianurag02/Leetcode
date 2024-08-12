// ---------------------------------- Approach - 1 --------------------------------

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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next){
            return head;
        }

        ListNode* smaller = new ListNode(-1);
        ListNode* greater = new ListNode(-1);

        ListNode* dummyG = greater;
        ListNode* dummyS = smaller;

        while(head){
            if(head->val >= x){
                dummyG->next = head;
                dummyG = head;
            } else {
                dummyS->next = head;
                dummyS = head;
            }

            head = head->next;
        }

        dummyG->next = NULL;
        dummyS->next = greater->next;

        return smaller->next;
    }
};