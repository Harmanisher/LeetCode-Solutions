class Solution {
public:

    void flatten(TreeNode* root) {
        if(root==nullptr) return;


        flatten(root->right);
        flatten(root->left);
        if(root->left != nullptr)
        {
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = NULL;

            TreeNode* curr = root->right;
            while(curr->right!=nullptr)
            {
                curr = curr->right;
            }
            curr->right = temp;
        }
    }
};