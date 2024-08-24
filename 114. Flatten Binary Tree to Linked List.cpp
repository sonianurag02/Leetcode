// ---------------------------- Approach - 1 -------------------------------------

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preOrder(TreeNode* root, vector<TreeNode*>& preorder){
        if(!root) return;

        preorder.push_back(root);
        preOrder(root->left, preorder);
        preOrder(root->right, preorder);
    }

    void flatten(TreeNode* root) {
        if(!root) return;

        vector<TreeNode*> preorder;
        preOrder(root, preorder);

        for(int i = 1; i < preorder.size(); i++){
            root->left = NULL;
            root->right = preorder[i];
            root = root->right;
        }
    }
};