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
    void Inorder(TreeNode* root, vector<int>&ans)
    {
        if(root == nullptr) return;

        Inorder(root->left, ans);
        ans.emplace_back(root->val);
        Inorder(root->right,ans);
    }

    TreeNode* RecoverInorder(TreeNode* root, vector<int>&ans, int &i)
    {
        if(root == NULL) return NULL;

        RecoverInorder(root->left,ans,i);

        if(root->val != ans[i]) root->val = ans[i];
        i++;

        RecoverInorder(root->right,ans,i);

        return root;
    }

    void recoverTree(TreeNode* root) {
        
        vector<int> ans;
        int i = 0;
        Inorder(root,ans);
        sort(ans.begin(), ans.end());

        TreeNode* result = RecoverInorder(root,ans,i);

    }
};