// ------------------------ Approach - 1 -----------------------------
// Using level order traversal

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> res;
        queue<TreeNode*> que;

        que.push(root);

        while(!que.empty()){
            int n = que.size();

            long long sum = 0;

            while(n--){
                TreeNode* node = que.front();
                que.pop();

                sum += (long long)node->val;

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(sum);
        }

        if(k > res.size()) return -1;

        sort(res.begin(), res.end(), greater<long long>());

        return res[k-1];
    }
};