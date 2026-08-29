class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode *>q;

        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            double sum = 0;
            for(int i=0; i<size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                sum+= temp->val;

                if(temp->left!=nullptr)
                {
                    q.push(temp->left);
                }
                if(temp->right!=nullptr)
                {
                    q.push(temp->right);
                }
            }
            ans.emplace_back((double)sum/size);
        }
        return ans;
    }
};