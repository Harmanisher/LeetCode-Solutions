
class Solution {
    void swapChild(TreeNode* &root)
    {
        if(root==nullptr)
        {
            return;
        }

        swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        swapChild(root);

        return root;
    }
};