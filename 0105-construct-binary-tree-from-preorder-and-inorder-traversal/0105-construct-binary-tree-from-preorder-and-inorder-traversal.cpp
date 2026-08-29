class Solution {
public:
    TreeNode* buildTree(vector<int>&preorder, int prestart, int preend, vector<int>&inorder, int instart, int inend, unordered_map<int,int>&mpp)
    {
        if(prestart>preend) return NULL;

        TreeNode* root = new TreeNode(preorder[prestart]);

        int inroot = mpp[root->val];
        int leftElements = inroot-instart;

        root->left = buildTree(preorder, prestart+1, prestart+leftElements, inorder, instart, inroot-1,mpp);

        root->right = buildTree(preorder, prestart+leftElements+1 ,preend, inorder,
        inroot+1, inend,mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;

        int n = preorder.size();
        int m = inorder.size();

        for(int i=0; i<m; i++)
        {
            mpp[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder,0,n-1, inorder, 0, m-1,mpp);

        return root;
    }
};