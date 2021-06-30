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

int lh = 0, rh = 0;
// lh --> Height of left subtree
// rh --> Height of right subtree

class Solution {
public:
    int diameter(TreeNode* root, int &h) {
        int path = INT_MIN;
        int lh = 0, rh = 0;
        
        if(root == NULL) {
            h = 0;
            return 0;
        }
        
        int ldiameter = diameter(root->left, lh);   //Diameter of left subtree
        int rdiameter = diameter(root->right, rh);  //Diameter of right subtree
       
        h = max(lh, rh) + 1;
          //  Return max of-
          // 1) Diameter of left subtree
          // 2) Diameter of right subtree
          // 3) Height of left subtree + height of right subtree  
        return max(max(ldiameter, rdiameter), lh + rh);
    }
    
    int diameterOfBinaryTree(TreeNode *root) {
       int height = 0;
       return diameter(root, height);
    }
};
