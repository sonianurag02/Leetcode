// ----------------------- Approach - 1 ------------------------------------

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
    ListNode* mergeTwoSortedLists(ListNode* L1, ListNode* L2){
        if(!L1) return L2;
        if(!L2) return L1;

        if(L1-> val <= L2->val){
            L1->next = mergeTwoSortedLists(L1->next, L2);

            return L1;
        }
        else{
            L2->next = mergeTwoSortedLists(L1, L2->next);

            return L2;
        }
        return NULL;
    } 

    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists){
        if(start > end){
            return NULL;
        }

        if(start == end){
            return lists[start];
        }

        int mid = start + (end-start) / 2;

        ListNode* L1 = partitionAndMerge(start, mid, lists);
        ListNode* L2 = partitionAndMerge(mid+1, end, lists);

        return mergeTwoSortedLists(L1, L2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if(k == 0) return NULL;

        return partitionAndMerge(0, k-1, lists);
    }
};