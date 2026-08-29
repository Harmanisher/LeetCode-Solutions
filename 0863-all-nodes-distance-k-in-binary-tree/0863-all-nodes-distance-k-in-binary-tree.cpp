class Solution {
    // ** First Function to Mark the Parent Nodes.
    void MarkParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&Parents)
    {
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode * temp = q.front();
            q.pop();

            if(temp->left != nullptr)
            {
                q.push(temp->left);
                Parents[temp->left] = temp;
            }
            if(temp->right != nullptr)
            {
                q.push(temp->right);
                Parents[temp->right] = temp;
            }
        }
    }
public:
    // **** Second  Function to find the distance.
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>Parents;

        MarkParent(root,Parents);

        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
        int level = 0;

        while(!q.empty())
        {
            int size = q.size();
            if(level++ == k) break;

            for(int i=0; i<size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left != nullptr && !visited[temp->left])
                {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right != nullptr && !visited[temp->right])
                {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if(Parents[temp] && !visited[Parents[temp]])
                {
                    q.push(Parents[temp]);
                    visited[Parents[temp]] = true;
                }
            }
        }

        vector<int>ans;
        while(!q.empty())
        {
            TreeNode *a = q.front();
            q.pop();

            ans.emplace_back(a->val);
        }

        return ans;
    }
};