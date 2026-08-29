// ************ The Logic used here is same as question : Same tree, but only thing we check here is, we compare left and right child. O(n). The first submitted code is also correct but here we just make it ore clean and easy to understand.
class Solution {
public:
    bool checkSame(TreeNode*p, TreeNode*q)
    {
        if(p==nullptr || q==nullptr)
        {
            return (p==q);
        }

        // if(p->val == q->val)
        // {
        //     if(checkSame(p->left,q->right)==false) return false;

        //     if(checkSame(p->right,q->left)==false) return false;

        //     else {
        //         return true;
        //     }
        // }
        // else
        // {
        //     return false;
        // }

        return ((p->val==q->val) && checkSame(p->left,q->right) && checkSame(p->right,q->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return false;

        bool result = checkSame(root->left, root->right);

        return result;
    }
};