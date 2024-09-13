// ---------------------------------- Approach - 1 ----------------------------------

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        que.push(root);

        if(root == NULL) return ans;
        
        int count = 0;
        
        while(1){
            int size = que.size();
            if(size == 0){
                return ans;
            }

            count++;
            vector<int> data;

            while(size > 0){
                TreeNode* temp = que.front();
                que.pop();

                data.push_back(temp->val);
                if(temp->left != NULL){
                    que.push(temp->left);
                }
                if(temp->right != NULL){
                    que.push(temp->right);
                }
                size--;
            }
            if(count % 2 == 0){
                reverse(data.begin(), data.end());
            }
            ans.push_back(data);
        }

        return ans;
    }
};