
class Solution {
public:
    bool checkBST(TreeNode* root, long long minValue, long long maxValue)
    {
        if(root == nullptr)
        {
            return true;
        }

        if(root->val <= minValue || root->val >= maxValue)
        {
            return false;
        }


        bool leftTree = checkBST(root->left, minValue, root->val);
        bool rightTree = checkBST(root->right, root->val, maxValue);

        return (leftTree && rightTree);
    }

    bool isValidBST(TreeNode* root) {
        long long  minValue = LLONG_MIN;
        long long  maxValue = LLONG_MAX;

        return checkBST(root,minValue,maxValue);
    }
};