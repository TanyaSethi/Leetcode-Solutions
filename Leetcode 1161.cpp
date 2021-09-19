/*
* 1161. Maximum Level Sum of a Binary Tree
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 1, sum = 0, maxSum = INT_MIN;;
        int pos = level;
        if(!root)
            return 0;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            TreeNode* f = q.front();
            q.pop();
            if(f == NULL) {
               if(sum > maxSum) {
                    maxSum = sum;
                    pos = level;
                }
                if(!q.empty())
                    q.push(NULL);
                sum = 0;
                level++;
            }
            else {
                
                sum += (f->val);
                if(f -> left)
                    q.push(f -> left);
                if(f -> right)
                    q.push(f -> right);
            }
            
        }
        return pos;
        
    }
};
