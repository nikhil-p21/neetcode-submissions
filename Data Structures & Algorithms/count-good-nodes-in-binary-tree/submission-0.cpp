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
    int count(TreeNode* root, int curr_max)
    {
        if(!root)return 0; 
        if(root->val>=curr_max)
        {
            curr_max = root->val; 
            return 1+count(root->left, curr_max)+count(root->right,curr_max); 
        }
        return count(root->left, curr_max)+count(root->right,curr_max); 
    }
    int goodNodes(TreeNode* root) {
        int curr_max = INT_MIN; 
        return count(root, curr_max); 
        
    }
};
