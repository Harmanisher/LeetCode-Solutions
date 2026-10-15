// Complexity: (O(n^2)) worst-case time and (O(h)) auxiliary stack space.

class Solution {
public:
    TreeNode* buildBST(vector<int> &preorder, int first, int last)
    {
        if(first>last) return NULL;

        TreeNode* root = new TreeNode(preorder[first]);

        int middle = last+1;

        //**** Find the next greater element:
        for(int i=first+1; i<=last; i++)
        {
            if(preorder[i] > preorder[first])
            {
                middle = i;
                break;
            }
        }

        root->left = buildBST(preorder,first+1,middle-1);

        root->right = buildBST(preorder,middle,last);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();

        TreeNode* root = buildBST(preorder, 0,n-1);

        return root;
    }
};