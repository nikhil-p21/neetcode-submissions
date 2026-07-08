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

class Codec {
public:
    string coded = ""; 
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
        {
            coded.push_back('#'); 
            coded.push_back('.'); 
            return coded; 
        }
        
        string curr_val = to_string(root->val);
        coded+=curr_val; 
        coded.push_back('.'); 
        serialize(root->left); 
        serialize(root->right); 
        return coded; 
    }

    TreeNode* helper(vector<string>&tokens, int &index)
    {
        if(index>=tokens.size())
        {
            return NULL; 
        }
        if(tokens[index]=="#")
        {
            index++; 
            return NULL; 
        }
        int curr_val = stoi(tokens[index]); 
        TreeNode* curr = new TreeNode(curr_val); 
        index++; 
        curr->left = helper(tokens, index);
        curr->right = helper(tokens, index); 
        return curr; 
        
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>tokens; 
        string curr= ""; 
        for(char &x: data)
        {
            if(x=='.')
            {
                tokens.push_back(curr); 
                curr = ""; 
            }
            else curr+=x; 
        }
        int index = 0; 
        return helper(tokens, index); 
    }
};
