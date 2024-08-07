// ----------------------------- Approach - 1 -----------------------------------

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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
            ListNode* start=temp;
            ListNode* prev= new ListNode(-1);
            ListNode* dummy=prev;
            prev->next=head;
             
        while(temp){
            ListNode* kth= start;
            for(int i=0;i<k-1;i++){
                if(kth==nullptr){
                break;
            }
            kth= kth->next;
            }
            if(kth==nullptr){
                break;
            }
            ListNode* connect= kth->next;
            kth->next= nullptr;
            ListNode* reverse= reverseList(start);
            prev->next=reverse;
             prev= start;

            start->next=connect;
            start=connect;   
            temp=start;        

        }
        return dummy->next;
    }
};