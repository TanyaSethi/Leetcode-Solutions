/**
  * 112. Path Sum
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPath(root, targetSum, targetSum);
    }
    bool hasPath(TreeNode* root, int sumLeft, int target) {
        if(!root)
            return false;
        if(root -> left == NULL && root->right == NULL) {
            if(root->val == sumLeft)
                return true;
            return false;
        }
            return hasPath(root->left, sumLeft - root->val, target) || hasPath(root->right, sumLeft - root->val, target);
        
    }
};
