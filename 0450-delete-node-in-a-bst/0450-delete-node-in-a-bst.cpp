class Solution {
public:
    TreeNode* searchNode(TreeNode* root, TreeNode* &p, int val) {
        while(root!=nullptr && root->val!=val)
        {
            if(val < root->val)
            {
                p = root;
                root = root->left;
            }
            else
            {   
                p = root;
                root = root->right;
            }
        }
        return root;
    }

    TreeNode* findInorder(TreeNode* Node, TreeNode* &parent)
    {
        TreeNode* replaceNode = Node->right;

        while(replaceNode->left != nullptr)
        {
            parent = replaceNode;
            replaceNode = replaceNode->left;
        }

        return replaceNode;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        TreeNode* p = root;

        TreeNode* Node = searchNode(root,p,key);
        
        //If key is not there:
        if(Node == nullptr) return root;

//********* If the Node to be deleted is the Leaf Node.
        if(Node->left == nullptr && Node->right == nullptr)
        {
            if(Node == p)
            {
                root = NULL;
            }
            else if(p->left == Node) p->left = nullptr;
            else
            {
                p->right = nullptr;
            }
            return root;
        }

        // ***** If the Node has 1 children
        else if(Node->left == nullptr || Node->right == nullptr)
        {
            if(Node==p)
            {
                if(Node->left == nullptr)
                {
                    root = root->right;
                }
                else
                {
                    root = root->left;
                }
            }
            else if(Node->left == nullptr)
            {
                if(p->left == Node) p->left = Node->right;
                else
                {
                    p->right = Node->right;
                }
            }
            else
            {
                if(p->left == Node) p->left = Node->left;
                else
                {
                    p->right = Node->left;
                }
            }
            return root;
        }

        // **** If the Node has 2 children
        else
        {
            TreeNode* ParentSuccessor = Node;
            TreeNode* successor = findInorder(Node,ParentSuccessor);

            if(Node == p)
            {
                if(Node->right == successor)
                {
                    successor->left = Node->left;
                    root = successor;
                }
                else
                {
                    ParentSuccessor->left = successor->right;
                    successor->left = Node->left;
                    successor->right = Node->right;
                    root = successor;
                }
            }
            else
            {
                if(Node->right == successor)
                {
                    if(p->right == Node)
                    {
                        successor->left = Node->left;
                        p->right = successor;
                    }
                    else
                    {
                        successor->left = Node->left;
                        p->left = successor;
                    }
                }
                else
                {
                    if(p->right == Node)
                    {
                        ParentSuccessor->left = successor->right;
                        successor->left = Node->left;
                        successor->right = Node->right;
                        p->right = successor;
                    }
                    else
                    {
                        ParentSuccessor->left = successor->right;
                        successor->left = Node->left;
                        successor->right = Node->right;
                        p->left = successor;
                    }
                }
            }
            return root;
        }
        return root;
    }
};