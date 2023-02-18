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
        int count=0;
public:
    int pathSum(TreeNode* root, long targetSum) {
        get(root,targetSum);
        return count;
    }

    //每一个都当做开始节点，从此节点遍历相加
    void get(TreeNode* root, long targetSum) {
        if (!root) return;
        process(root,targetSum);
        get(root->left,targetSum);
        get(root->right,targetSum);
    }
    //不断从该节点往下遍历
    void process(TreeNode* root, long targetSum) {
        if (!root) return;
        if (root->val==targetSum) count++;

        process(root->left,targetSum-root->val);
        process(root->right,targetSum-root->val);
    }
};