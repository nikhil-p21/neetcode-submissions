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
    void traverse(TreeNode* root, vector<int>&traversal)
    {
        if(root->left)traverse(root->left, traversal); 
        traversal.push_back(root->val); 
        if(root->right)traverse(root->right, traversal); 
       

    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true; 
        vector<int>traversal; 
        traverse(root, traversal); 
        if(traversal.size()==1)return true; 
        for(int i=1; i<traversal.size(); i++)
        {
            if(traversal[i]<=traversal[i-1])return false;
        }
        return true; 
        
    }
};
