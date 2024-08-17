// ------------------------- Approach - 1 -----------------------------

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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        if(!root->left && !root->right)
            return 1;

        queue<TreeNode*> que;
        que.push(root);

        int depth = 0;

        while(!que.empty()){
            ++depth;

            for(int i = 0, n = que.size(); i < n; ++i){
                TreeNode* temp = que.front();
                que.pop();

                if(temp->left != NULL) que.push(temp->left);
                if(temp->right != NULL) que.push(temp->right);
            }
        }
        return depth;
    }
};