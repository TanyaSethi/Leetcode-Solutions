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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool direction = false;
        vector<int> result;  
        vector<vector<int>> values;
        deque<TreeNode*> q;
        if(root == NULL)
            return values;
        q.push_back(root);
       
        while(!q.empty()) {
            deque<TreeNode*> dq;
            result.clear();
            int count = q.size();
            for(int i  = 0; i < count; ++i) {
                
                TreeNode* node = q.front();
                q.pop_front();
                
                result.push_back(node->val);
                if(direction) {
                    if(node->right)
                        dq.push_front(node->right);   
                    if(node -> left)
                        dq.push_front(node -> left);
                }
                else {
                    if(node -> left)
                        dq.push_front(node -> left);                       
                    if(node->right)
                        dq.push_front(node->right);            
                }          
            }
            direction = !direction;
            q.insert(q.end(), dq.begin(), dq.end());
             
            values.push_back(result);
        }
        
        return values;
    }
};
