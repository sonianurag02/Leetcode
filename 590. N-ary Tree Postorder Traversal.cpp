// ------------------------------- Approach - 1 ---------------------------------

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void postOrder(Node* root, vector<int>& res){
        if(!root){
            return;
        }

        cout<<root->children.size()<<" ";

        for(int i = 0; i < root->children.size(); i++){
            postOrder(root->children[i], res);
            res.push_back(root->children[i]->val);
        }
    }

    vector<int> postorder(Node* root) {
        if(!root){
            return {};
        }

        vector<int> result;

        postOrder(root, result);

        result.push_back(root->val);

        return result;
    }
};