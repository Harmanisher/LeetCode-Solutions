class Solution {
public:
    TreeNode* buildTree(vector<int>&postorder, int poststart, int postend, vector<int>&inorder, int instart, int inend, unordered_map<int,int>&mpp)
    {
        if(poststart > postend) return NULL;

        TreeNode* root = new TreeNode(postorder[postend]);

        int inroot = mpp[root->val];
        int leftElements = inroot - instart;

        root->left = buildTree(postorder, poststart, poststart+leftElements-1, inorder, instart, inroot-1, mpp);

        root->right = buildTree(postorder, poststart+leftElements, postend-1, inorder, inroot+1, inend, mpp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mpp;

        int n = inorder.size();
        int m = postorder.size();

        for(int i=0; i<n; i++)
        {
            mpp[inorder[i]] = i;
        }

        TreeNode* root = buildTree(postorder, 0,m-1,inorder, 0, n-1,mpp);
        return root;
    }
};