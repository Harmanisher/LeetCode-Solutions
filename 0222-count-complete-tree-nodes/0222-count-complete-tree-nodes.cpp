// This code is exactly same as the First submitted code. But in this i provide the explaination. The compleete binary tree is a tree whose all the levels are fully filled except the last level, but if the last level has nodes then it must be from left to right completely without leaving a gap between them. If a tree is fully filled then it total nodes are (2^height of the tree)-1. so, we recursively check wheteher tree is fully filled by comparing left and right height and use the formula. if yes then we recursively return 1+(leftHeight+rightHeight);
class Solution {
public:
    int leftHeight(TreeNode* root)
    {
        int lh = 0;

        while(root)
        {
            lh++;
            root = root->left;
        }
        return lh;
    }
    int rightHeight(TreeNode* root)
    {
        int rh = 0;

        while(root)
        {
            rh++;
            root = root->right;
        }
        return rh;
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;

        int left = leftHeight(root);
        int right = rightHeight(root);

        if(left==right)
        {
            return (1<<left)-1;
        }
        
        return 1+(countNodes(root->left) + countNodes(root->right));
    }
};