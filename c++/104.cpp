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
    int res;
public:
    int maxDepth(TreeNode* root) {
        res = 0;
        depth(root,0);
        return res;
    }
    void depth(TreeNode* root, int d){
        if(!root){
            res = max(res,d);
            return;
        }
        depth(root->left,d+1);
        depth(root->right,d+1);
    }
};