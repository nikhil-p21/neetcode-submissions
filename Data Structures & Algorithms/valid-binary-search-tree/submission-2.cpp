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
    bool traverse(TreeNode* root, vector<int>&traversal)
    {
        bool is_left = true, is_right = true;
        if(root->left)is_left&=traverse(root->left, traversal); 
        if(!traversal.empty())
        {
            if(root->val<=traversal.back())return false; 
            
        }
        traversal.push_back(root->val);
        if(root->right)is_right&=traverse(root->right, traversal); 

        return is_left && is_right; 
       

    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true; 
        vector<int>traversal; 
        return traverse(root, traversal); 
      
        
    }
};
