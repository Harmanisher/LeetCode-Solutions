class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;

        queue<pair<TreeNode *, long long>>q;

        q.push({root,0});
        int ans = 0;

        while(!q.empty())
        {
            int size = q.size();
            int first,last;
            int min = q.front().second;
            for(int i=0; i<size; i++)
            {
                TreeNode* temp = q.front().first;
                long long id = q.front().second - min;
                q.pop();

                if(i==0) first = id;
                if(i==(size-1)) last = id;

                if(temp->left != nullptr)
                {
                    q.push({temp->left,2*id+1});
                }
                if(temp->right != nullptr)
                {
                    q.push({temp->right,2*id+2});
                }
            }
            ans = max(ans,(last-first+1));
        }
       return ans; 
    }
};