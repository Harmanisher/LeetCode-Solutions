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
// ****** This function is of maximum depty of binary tree
    int height(TreeNode* root) {
        
        if(root==nullptr) return 0;

        int left = height(root->left);
        int right = height(root->right);

        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)return true;

        int lheight = height(root->left);
        int rheight = height(root->right);

        if(abs(lheight-rheight)>1) return false;

        // bool left = isBalanced(root->left);
        // bool right = isBalanced(root->right);

        // if(!left || !right) return false;
        // return true;

        return(isBalanced(root->left) && isBalanced(root->right));
    }
};