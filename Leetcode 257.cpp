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
    vector<string> result;
    vector<string> binaryTreePaths(TreeNode* root) {
        calculate_paths(root, to_string(root->val));
        return  result;
    }
    
    void calculate_paths(TreeNode* root, string s) {
        if(!root)
            return;
        if(root -> left == NULL &&  root -> right == NULL) {
            result.push_back(s);
            return;
        }
        
        if(root->left) calculate_paths(root -> left, s + "->" + to_string(root->left->val));
        if(root->right) calculate_paths(root ->  right, s + "->" + to_string(root->right->val));
    }
};
