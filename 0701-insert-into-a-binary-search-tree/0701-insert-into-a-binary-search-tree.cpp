class Solution {
public:
    void findInsertion(TreeNode* root, int val)
    {
        if(val < root->val)
        {
            if(root->left == nullptr)
            {
                TreeNode* newNode = new TreeNode(val);
                root->left = newNode;
                return;
            }
            else
            {
                findInsertion(root->left, val);
            }
        }

        else if(val > root->val)
        {
            if(root->right == nullptr)
            {
                TreeNode* newNode = new TreeNode(val);
                root->right = newNode;
                return;
            }
            else
            {
                findInsertion(root->right, val);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(root == NULL)
        {
            TreeNode* newNode = new TreeNode(val);
            root = newNode;
        }
        
        findInsertion(root,val);

        return root;
    }
};