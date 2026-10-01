
class Solution {
public:
    int Inorder(TreeNode* root, int &count, int &ans, int k)
    {
        if(root == nullptr) return 0;

        if(Inorder(root->left, count, ans, k) == -1) return -1;

        count++;
        if(count == k)
        {
            ans = root->val;
             return -1;
        }

        if(Inorder(root->right, count, ans, k) == -1) return -1;

        return ans;
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = 0;

        int result = Inorder(root,count,ans,k);

        return ans;
    }
};