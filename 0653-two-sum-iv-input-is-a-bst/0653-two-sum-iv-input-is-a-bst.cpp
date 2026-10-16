// *** In this first i find the inorder(we can take any pre or postorder also). Then i use the Hashtable concept of the 2 sum question in that;
class Solution {
public:
    void Inorder(TreeNode* root, vector<int> &ans)
    {       
        if(root == nullptr) return;

        Inorder(root->left,ans);
        ans.emplace_back(root->val);
        Inorder(root->right,ans);

    }
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> ans;
        map<int,int>mpp;

        Inorder(root,ans);

        int n = ans.size();

        for(int i=0; i<n; i++)
        {
            int elefound = k-ans[i];

            if(mpp.find(elefound) != mpp.end())
            {
                return true;
            }
            else
            {
                mpp[ans[i]] = i;
            }
        }

        return false;
    }
};