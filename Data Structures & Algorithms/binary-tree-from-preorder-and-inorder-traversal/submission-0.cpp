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
    TreeNode* makeTree(vector<int>&preorder, vector<int>&inorder, int start, int end, int &index)
    {
        if(start>end)
        {
            return NULL; 
        }
        int curr_val= preorder[index]; 
        TreeNode* curr = new TreeNode(curr_val); 
        int pos = 0; 
        for(int x=start; x<=end; x++)
        {
            if(inorder[x]==curr_val)
            {
                pos = x; 
                break; 
            }
        }
        index++; 
        curr->left = makeTree(preorder, inorder, start, pos-1, index); 
        curr->right = makeTree(preorder, inorder, pos+1, end, index); 

        return curr; 

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size(); 
        int index = 0; 
        return makeTree(preorder, inorder, 0, n-1, index); 
    }
};