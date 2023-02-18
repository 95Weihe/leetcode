/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root=new TreeNode();
        preOrder(root,root1,root2);
        return root;
    }
    
    void preOrder(TreeNode*& root, TreeNode* root1, TreeNode* root2){
        if(!root1&&!root2){
            root = nullptr;
        }else{
            int t = (root1?root1->val:0)+(root2?root2->val:0);
            root = new TreeNode(t);
            preOrder(root->left,root1?root1->left:nullptr,root2?root2->left:nullptr);
            preOrder(root->right,root1?root1->right:nullptr,root2?root2->right:nullptr);
        }
    }
};