// ----------------------------------- Approach - 1 --------------------------------
// Using map

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }

        unordered_map<Node*, Node*> mp;

        Node* curr = head;
        Node* prev = NULL;
        Node* newHead = NULL;

        while(curr){
            Node* temp = new Node(curr->val);

            mp[curr] = temp;

            if(newHead == NULL){
                newHead = temp;
                prev = newHead;
            } else{
                prev->next = temp;
                prev = temp;
            }

            curr = curr->next;
        }

        curr = head;
        Node* newCurr = newHead;

        while(curr){
            if(curr->random == NULL){
                newCurr->random = NULL;
            } else {
                newCurr->random = mp[curr->random];
            }

            curr = curr->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }
};

// ----------------------------------- Approach - 2 --------------------------------

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }

        // Insert the new nodes in between the original linked list
        Node* curr = head;

        while(curr){
            Node* currNext = curr->next;
            curr->next = new Node(curr->val); // A -> B
            curr->next->next = currNext;      // A -> X -> B

            curr = currNext;                  // curr = B
        }

        // Deep copy of random pointers
        curr = head;

        while(curr && curr->next){
            if(curr->random == NULL){
                curr->next->random = NULL;
            } else {
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        // Separate the linked lists
        Node* newHead = head->next;
        Node* newCurr = newHead;
        curr = head;

        while(curr && newCurr){
            curr->next = curr->next == NULL ? NULL : curr->next->next;
            newCurr->next = newCurr->next == NULL ? NULL : newCurr->next->next;

            curr = curr->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }
};