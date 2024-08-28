// --------------------------------------- Approach - 1 -----------------------------------------

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;

        queue<TreeNode*> que;

        que.push(root);
        que.push(NULL);
        double sum = 0;
        int count = 0;

        while(!que.empty()){
            TreeNode* front = que.front();
            que.pop();

            if(front == NULL){
                double avg = sum / count;
                result.push_back(avg);

                sum = 0;
                count = 0;
                if(que.size() > 0){
                    que.push(NULL);
                }
            } 
            else {
                sum += front ->val;
                count++;

                if(front->right){
                    que.push(front->right);
                }

                if(front->left){
                    que.push(front->left);
                }
            }
        }

        return result;
    }
};