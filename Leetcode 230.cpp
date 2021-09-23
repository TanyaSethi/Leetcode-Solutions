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
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        ksmallest(root, k, result);
        return result;
    }
    
    void ksmallest(TreeNode* root, int &k, int &result) {
        if(!k)
            return;
        if(root) { 
            ksmallest(root->left, k, result);
            if(k == 1) {
                result = root->val;
            }
            --k;
            ksmallest(root->right, k, result);
       }
    }
};
