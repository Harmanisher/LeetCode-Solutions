// In this i am going to use reverse of Preorder traversal, ie. general preorder follorw :- Root,Left,Right. In this i convert it into :- Root, Right, Left. plus a small smart technique. we kee[ track of each visited level and we add elements only if we have not visited that level.
class Solution {
public:

    void ReversePreorder(TreeNode* root, int level, vector<int> &ans)
    {
        if(root==nullptr) return;

        if(ans.size() == level)
        {
            ans.emplace_back(root->val);
        }

        ReversePreorder(root->right, level+1,ans);
        ReversePreorder(root->left, level+1,ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if(root==nullptr) return ans;
        ReversePreorder(root,0,ans);

        return ans;    
    }
};