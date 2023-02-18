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
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        postOrder(root,res);
        return res-1;
    }

    int postOrder(TreeNode* root, int& res){
        if(!root) return 0;
        int l = postOrder(root->left, res);
        int r = postOrder(root->right, res);
        res = max(res,l+r+1);
        return max(l,r)+1;
    }
};