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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        // if(!root->left&&!root->right) return true;
        // if(root->left&&!root->right) return false;
        // if(!root->left&&root->right) return false;
        return isSame(root->left,root->right);
        // if(root->left->val!=root->right->val) return false;
    }
    bool isSame(TreeNode* l, TreeNode* r){
        if(!l&&!r) return true;
        if(l&&!r) return false;
        if(!l&&r) return false;
        if(l->val!=r->val) return false;
        bool lr = isSame(l->left,r->right);
        bool rr = isSame(l->right,r->left);
        return lr&&rr;
    }
};