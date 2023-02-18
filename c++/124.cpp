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
/*
基本框架：后序遍历
结果最大值：一定是左、右子树 和为正 者加上当前节点
当后序遍历向上（父节点）延伸时，左右子树最多只能选其一：则较大者且和为正者
*/
class Solution {
    int res;
public:
    int maxPathSum(TreeNode* root) {
        res = -1000;
        dfs(root);
        return res;
    }
    int dfs(TreeNode* t){
        if(!t) return 0;
        int ls = dfs(t->left);
        int rs = dfs(t->right);
        int cur = max(0,ls)+max(0,rs)+t->val;
        res = max(cur,res);
        return max(0,max(ls,rs)+t->val);
    }
};