// --------------------------------- Approach - 1 ----------------------------------

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
    void inorder(TreeNode* root, vector<int>& vec)
    {
        if(root==NULL)
        {
            return;
        }

        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }

        vector<int> v;

        inorder(root, v);

        sort(v.begin(), v.end());

        int ans=abs(v[0] - v[1]);

        for(int i = 2;i < v.size(); i++)
        {
            ans = min(ans, abs(v[i] - v[i-1]));
        }

        return ans;
    }
};