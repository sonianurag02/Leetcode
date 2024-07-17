// --------------------------------------- Approach - 1 -------------------------------------

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
private:
    TreeNode* processNode(TreeNode* node, unordered_set<int>& toDeleteSet, vector<TreeNode*>& forest){
        if(!node) return nullptr;

        node->left = processNode(node->left, toDeleteSet, forest);
        node->right = processNode(node->right, toDeleteSet, forest);

        if(toDeleteSet.find(node->val) != toDeleteSet.end()){
            if(node->left){
                forest.push_back(node->left);
            }
            if(node->right){
                forest.push_back(node->right);
            }
            delete node;
            return nullptr;
        }

        return node;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;

        root = processNode(root, toDeleteSet, forest);

        if(root){
            forest.push_back(root);
        }

        return forest;
    }
};

// --------------------------------------- Approach - 2 -------------------------------------

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return {};

        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            TreeNode* currNode = que.front();
            que.pop();

            if(currNode->left){
                que.push(currNode->left);
                if(toDeleteSet.find(currNode->left->val) != toDeleteSet.end()){
                    currNode->left = nullptr;
                }
            }

            if(currNode->right){
                que.push(currNode->right);
                if(toDeleteSet.find(currNode->right->val) != toDeleteSet.end()){
                    currNode->right = nullptr;
                }
            }

            if(toDeleteSet.find(currNode->val) != toDeleteSet.end()){
                if(currNode->left){
                    forest.push_back(currNode->left);
                }
                if(currNode->right){
                    forest.push_back(currNode->right);
                }
            }
        }

        if(toDeleteSet.find(root->val) == toDeleteSet.end()){
            forest.push_back(root);
        }

        return forest;
    }
};