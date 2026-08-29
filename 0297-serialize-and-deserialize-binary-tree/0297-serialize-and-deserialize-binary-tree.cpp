/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "";
        
        queue<TreeNode *>q;
        q.push(root);
        string s="";
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL)
            {
                s.append("#,");
            }
            else
            {
                s.append(to_string(temp->val)+',');
            }
            if(temp!=NULL)
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;

        stringstream ss(data);
        string token;

        getline(ss,token,',');

        queue<TreeNode* >q;
        TreeNode * root = new TreeNode(stoi(token));
        q.push(root);

        while(!q.empty())
        {
            TreeNode * temp = q.front();
            q.pop();
            
            getline(ss,token,',');

            if(token == "#")
            {
                temp->left = NULL;
            }
            else
            {
                TreeNode* l = new TreeNode(stoi(token));
                temp->left = l;
                q.push(l);
            }

            getline(ss,token,',');
            if(token == "#")
            {
                temp->right = NULL;
            }
            else
            {
                TreeNode* r = new TreeNode(stoi(token));
                temp->right = r;
                q.push(r);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));