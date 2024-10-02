// ----------------------- Approach - 1 ---------------------------------
// Using unordered map and ordered set

class AllOne {
public:
    unordered_map<string, int> count;
    set<pair<int, string>> st;

    AllOne() {
        count.clear();
    }
    
    void inc(string key) {
        int n = count[key];
        count[key]++;
        st.erase({n, key});
        st.insert({n+1, key});
    }
    
    void dec(string key) {
        int n = count[key];
        count[key]--;
        st.erase({n, key});
        if(count[key] > 0) st.insert({n-1, key});
        else count.erase(key);
    }
    
    string getMaxKey() {
        if(!st.empty()) return st.rbegin()->second;
        return "";
    }
    
    string getMinKey() {
        if(!st.empty()) return st.begin()->second;
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

// ----------------------- Approach - 2 ---------------------------------
// Using unordered map and doubly linked list

class AllOne {
public:
    struct Node{
        int count; // freq
        list<string> keys;
        Node* prev;
        Node* next;
        Node(int c){
            count = c;
            prev = nullptr;
            next = nullptr;
        }
    };

    unordered_map<string, Node*> mp;

    Node* head; // head->next will be the min key string
    // Node* first; // min key string
    Node* last; // max key string

    void addNode(Node* prevNode, int count){
        Node* newNode = new Node(count);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if(newNode->next != NULL){
            newNode->next->prev = newNode;
        }

        prevNode->next = newNode;
        if(prevNode == last){
            last = newNode;
        }
    }

    void removeNode(Node* node){
        node->prev->next = node->next;
        if(node->next != NULL){
            node->next->prev = node->prev;
        }

        if(last == node){
            last = node->prev;
        }

        delete node;
    }

    AllOne() {
        head = new Node(0);
        last = head;
    }
    
    void inc(string key) {
        if(mp.find(key) == mp.end()){
            // not exists
            // check if there is alerdy a node with count = 1;
            if(head->next == nullptr || head->next->count != 1){
                addNode(head, 1); // head->next = newNode
            }

            head->next->keys.push_front(key);
            mp[key] = (head->next);
        } else { // key is already there in the map
            // increase it's frequency -> move to +1 frequency node
            Node* currNode = mp[key];
            int currCount = currNode->count; // 2 -> 3
            if(currNode->next == nullptr || currNode->next->count != currCount+1){
                addNode(currNode, currCount+1);
            }

            currNode->next->keys.push_front(key);
            mp[key] = currNode->next;
            currNode->keys.remove(key);
            if(currNode->keys.empty()){
                removeNode(currNode);
            }
        }
    }
    
    void dec(string key) {
        Node* currNode = mp[key];
        int currCount = currNode->count;
    

        // Remove the kkey if count becomes 0
        if(currCount == 1){
            mp.erase(key);
        } else {
            if(currNode->prev->count != currCount - 1){
                addNode(currNode->prev, currCount - 1);
            }
            currNode->prev->keys.push_front(key);
            mp[key] = currNode->prev;
        }

        currNode->keys.remove(key);
        if(currNode->keys.empty()){
            removeNode(currNode);
        }
    }
    
    string getMaxKey() {
        if(last == head){ // no nodes avalable
            return "";
        }

        return last->keys.front();
    }
    
    string getMinKey() {
        if(head->next == nullptr){
            return "";
        }

        return head->next->keys.front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */