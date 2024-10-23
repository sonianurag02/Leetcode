// ------------------------------- Approach - 1 -------------------------------------
// Using level order traversal
// T.C.: O(2n)

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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }

        queue<TreeNode*> que;
        que.push(root);
        vector<int> levelSum;

        // Step - 1: find sum of each level and store in levelsum array
        while(!que.empty()){
            int currLevelSum = 0;
            int n = que.size();

            while(n--){
                TreeNode* node = que.front();
                que.pop();

                currLevelSum += node->val;

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }

            levelSum.push_back(currLevelSum);
        }

        // Step - 2: Update each node value with cousin sum
        que.push(root);
        root->val = 0; // root has no cousins
        int i = 1;

        while(!que.empty()){
            int n = que.size(); // How many nodes are in current level

            while(n--){
                TreeNode* curr = que.front();
                que.pop();

                // levelSum of currentLevel - siblingSum
                int siblingSum = curr->left != NULL ? curr->left->val : 0;
                siblingSum += curr->right != NULL ? curr->right->val : 0;

                if(curr->left){
                    curr->left->val = levelSum[i] - siblingSum;
                    que.push(curr->left);
                }
                if(curr->right){
                    curr->right->val = levelSum[i] - siblingSum;
                    que.push(curr->right);
                }
            }
            i++;
        }

        return root;
    }
};

// ------------------------------- Approach - 2 -------------------------------------
// T.C.: O(n)

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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }

        queue<TreeNode*> que;
        que.push(root);
        int levelSum = root->val;

        while(!que.empty()){
            int n = que.size();
            int nextLevelSum = 0;

            while(n--){
                TreeNode* curr = que.front();
                que.pop();

                curr->val = levelSum - curr->val;

                int siblingSum = (curr->left != NULL ? curr->left->val : 0);
                siblingSum += (curr->right != NULL ? curr->right->val : 0);

                if(curr->left) {
                    nextLevelSum += curr->left->val;
                    curr->left->val = siblingSum;
                    que.push(curr->left);
                }

                if(curr->right) {
                    nextLevelSum += curr->right->val;
                    curr->right->val = siblingSum;
                    que.push(curr->right);
                }
            }

            levelSum = nextLevelSum;
        }

        return root;
    }
};