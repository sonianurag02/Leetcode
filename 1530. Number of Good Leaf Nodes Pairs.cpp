// ------------------------------------ Approach - 1 -------------------------------------------

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
    void makeGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>>& adj, unordered_set<TreeNode*>& st){
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL){
            st.insert(root);
        }

        if(prev != NULL){
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        makeGraph(root->left, root, adj, st);
        makeGraph(root->right, root, adj, st);
    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj; // Graph
        unordered_set<TreeNode*> st; // Leaf Node

        makeGraph(root, NULL, adj, st);

        int count = 0; // Count of good node pair

        for(auto& leaf: st){
            queue<TreeNode*> que;
            unordered_set<TreeNode*> visited;

            que.push(leaf);
            visited.insert(leaf);

            for(int level = 0; level <= distance; level++){
                int size = que.size();
                while(size--){
                    TreeNode* cur = que.front();
                    que.pop();

                    if(cur != leaf && st.count(cur)){
                        count++;
                    }

                    for(auto& ngbr: adj[cur]){
                        if(!visited.count(ngbr)){
                            que.push(ngbr);
                            visited.insert(ngbr);
                        }
                    }
                }
            }
        }
        return count / 2;
    }
};

// ------------------------------------ Approach - 2 -------------------------------------------

