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
    int rob(TreeNode* root) {
        //思路：能盗取的最高金额为 抢劫该节点+抢劫该节点的左孩子的左右子树+抢劫该节点的右孩子的左右子树 与 抢劫该节点的左子树+抢劫该节点的右子树的和  的最大值
        // res.first代表不抢劫该节点时的最大值，res.second代表抢劫该节点时的最大值
        pair<int,int> res = dfs(root);
        return max(res.first,res.second);
    }
    pair<int,int> dfs(TreeNode* t){
        if(!t) return {0,0};
        pair<int,int> l = dfs(t->left);
        pair<int,int> r = dfs(t->right);
        //第二个值即为：抢劫该节点+抢劫该节点的左孩子的左右子树+抢劫该节点的右孩子的左右子树
        return {max(l.first,l.second)+max(r.first,r.second), l.first+r.first+t->val};
    }
};