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
//注意边界值：可将  int pre 初始化为空int指针：int* pre=nullptr
    int* pre = nullptr; 
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool l=isValidBST(root->left);
        if(!l||(pre!=nullptr&&*pre>=root->val)) return false;
        pre = &root->val;
        return isValidBST(root->right);
    }
};