// -------------------- Approach - 1 --------------------------
// DFS | unordered_map

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    void DFS(Node* node, Node* clone_node){
        for(Node* n: node->neighbors){
            if(mp.find(n) == mp.end()){
                Node* clone = new Node(n->val);
                mp[n] = clone;
                clone_node->neighbors.push_back(clone);

                DFS(n, clone);
            } else {
                clone_node->neighbors.push_back(mp[n]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        mp.clear();

        // Clone the given node
        Node* clone_node = new Node(node->val);

        // Now, clone its neighbours and recursively their neighbours
        /*
            But if a node reappears, then we need to access that cloned node
            So, store them in a map <Node*, Node*>
        */

        mp[node] = clone_node;
        
        DFS(node, clone_node);

        return clone_node;
    }
};

// -------------------- Approach - 2 --------------------------
// BFS | unordered_map

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    void DFS(Node* node, Node* clone_node){

        for(Node* n: node->neighbors){

            if(mp.find(n) == mp.end()){
                Node* clone = new Node(n->val);
                mp[n] = clone;
                clone_node->neighbors.push_back(clone);

                DFS(n, clone);
            } else {
                clone_node->neighbors.push_back(mp[n]);
            }

        }

    }

    void BFS(queue<Node*>& que){

        while(!que.empty()){
            Node* node = que.front();
            Node* clone_node = mp[node];
            que.pop();

            for(Node* n: node->neighbors){

                if(mp.find(n) == mp.end()){
                    Node* clone = new Node(n->val);
                    mp[n] = clone;
                    clone_node->neighbors.push_back(clone);

                    // DFS(n, clone);
                    que.push(n);
                } else {
                    clone_node->neighbors.push_back(mp[n]);
                }

            }

        }

    }

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        mp.clear();

        // Clone the given node
        Node* clone_node = new Node(node->val);

        // Now, clone its neighbours and recursively their neighbours
        /*
            But if a node reappears, then we need to access that cloned node
            So, store them in a map <Node*, Node*>
        */

        mp[node] = clone_node;
        
        queue<Node*> que;
        que.push(node);

        BFS(que);

        return clone_node;
    }
};