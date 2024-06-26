// ---------------------------------- Code ---------------------------------------

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
    void inorder(TreeNode* root, vector<int>& vec){
        if(!root) return;

        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }

    TreeNode* construct(int l, int r, vector<int> vec){
        if(l > r){
            return NULL;
        }

        int m = l + (r - l) / 2;

        TreeNode* root = new TreeNode(vec[m]);

        root->left = construct(l, m-1, vec);
        root->right = construct(m+1, r, vec);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);

        int l = 0;
        int r = vec.size() - 1;
        return construct(l, r, vec);
    }
};