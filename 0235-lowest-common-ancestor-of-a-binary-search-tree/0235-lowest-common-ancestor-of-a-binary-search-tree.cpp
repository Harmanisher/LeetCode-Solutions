

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* left = NULL;
        TreeNode*right = NULL;
        TreeNode* small;
        TreeNode* large;

        if(p->val<q->val)
        {
             small = p;
             large = q;
        }
        else
        {
             small = q;
             large = p;
        }


        if((small->val < root->val) && (large->val > root->val) || small==root || large==root)
        {
            return root;
        }

        else if((small->val < root->val) && (large->val < root->val))
        {
            left = lowestCommonAncestor(root->left, p, q);
        }
        else if((small->val > root->val) && (large->val > root->val))
        {
            right = lowestCommonAncestor(root->right, p, q);
        }

        if(left==NULL) return right;
        else
        {
            return left;
        }

        return root;
    }
};