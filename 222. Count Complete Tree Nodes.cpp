// ------------------------------- Approach - 1 -----------------------------------

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
    int countTraverse(TreeNode* root, int& num){
        if(!root) return 0;
        num++;

        countTraverse(root->left, num);
        countTraverse(root->right, num);
        return num;
    }

    int countNodes(TreeNode* root) {
        int num = 0;
        countTraverse(root, num);
        return num;
    }
};