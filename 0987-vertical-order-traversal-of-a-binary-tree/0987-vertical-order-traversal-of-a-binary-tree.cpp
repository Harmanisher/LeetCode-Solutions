// In this we first assign the store column and row values of each node and also node value in the map, because map sorts the data, we also use multiset here alo because multiset make teh data sorted along with duplicates. after storing values in map, we iterate through map and insert the elements in the particular vector and finally in the answer vector. Time complexity : O(nlogn)O(n). we can use any traversal to store elements in the map.
class Solution {
public:
    void preorder(TreeNode* root, map<int,map<int, multiset<int>>> &mpp, int row, int col)
    {
        if(root==nullptr) return;

        mpp[col][row].insert(root->val);

        preorder(root->left, mpp, row+1, col-1);
        preorder(root->right, mpp, row+1, col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int, multiset<int>>> mpp;
        vector<vector<int>> ans;

        preorder(root,mpp,0,0);

        for(auto i : mpp)
        {
            vector<int> vec;
            for(auto j : i.second)
            {
                vec.insert(vec.end(), j.second.begin(), j.second.end());
                
            }
            ans.emplace_back(vec);
        }

        return ans;
    }
};

// Note : Here, we use vec.insert instead of push_back or emplace_back, because emplace_back() is normally intended to construct one element, while insert() has a range overload for inserting many elements.