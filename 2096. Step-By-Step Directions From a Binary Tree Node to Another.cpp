// --------------------------------- Approach - 1 --------------------------------------------

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
    TreeNode* lowestCommonAncestor(TreeNode* root, int src, int dest){
        if(!root) return NULL;

        if(root->val == src || root->val == dest){
            return root;
        }

        TreeNode* l = lowestCommonAncestor(root->left, src, dest);
        TreeNode* r = lowestCommonAncestor(root->right, src, dest);

        if(l && r) return root;

        return l ? l : r;
    }

    bool findPath(TreeNode* LCA, int target, string& path){
        if(!LCA) return false;

        if(LCA->val == target) return true;

        // explore left
        path.push_back('L');
        if(findPath(LCA->left, target, path) == true){
            return true;
        }

        path.pop_back();

        // explore right
        path.push_back('R');
        if(findPath(LCA->right, target, path) == true){
            return true;
        }

        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {

        TreeNode* LCA = lowestCommonAncestor(root, startValue, destValue);

        string lcaToSrc = "";
        string lcaToDest = "";

        findPath(LCA, startValue, lcaToSrc);
        findPath(LCA, destValue, lcaToDest);

        string result = "";

        for(int i = 0; i < lcaToSrc.length(); i++){
            result.push_back('U');
        }

        result += lcaToDest;

        return result;
    }
};

// --------------------------------- Approach - 2 --------------------------------------------

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
    bool findPath(TreeNode* LCA, int target, string& path){
        if(!LCA) return false;

        if(LCA->val == target) return true;

        // explore left
        path.push_back('L');
        if(findPath(LCA->left, target, path) == true){
            return true;
        }

        path.pop_back();

        // explore right
        path.push_back('R');
        if(findPath(LCA->right, target, path) == true){
            return true;
        }

        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootToSrc = "";
        string rootToDest = "";

        findPath(root, startValue, rootToSrc);
        findPath(root, destValue, rootToDest);

        string result = "";

        int l = 0;

        while(l < rootToSrc.length() && l < rootToDest.length() && rootToSrc[l] == rootToDest[l]){
            l++;
        }

        // Add "U"
        for(int i = 0; i < rootToSrc.length() - l; i++){
            result.push_back('U');
        }

        for(int i = l; i < rootToDest.length(); i++){
            result.push_back(rootToDest[i]);
        }

        return result;
    }
};