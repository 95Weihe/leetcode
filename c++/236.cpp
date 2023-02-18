/*
功能具体实现：

1. 如果root等于p，返回p，因为：
* 如果树中有q，则p肯定是公共祖先，返回p
* 如果树中无q，则p也是公共祖先，仍然返回p（这种情况不存在）

2. 如果root等于q，同上返回q

3. 如果root==null，说明p、q都不在树中（空树），返回null

4. 如果以上不满足，说明p、q要么在子树中，要么不在树中，对root左右子节点调用函数
* 如果右子树为空，说明公共祖先在左子树中，会通过返回值呈递上来
* 如果左子树为空，说明公共祖先在右子树中，会通过返回值呈递上来
* 如果都为空，实际上也包含在上面两种情况中，返回null
* 如果都不为空，说明p、q分别在左右子树中，那么根节点root就是p、q公共祖先

关键理解：
若 p 为 q 的祖先，p 为 r 的左子，则 r 的右子树递归返回null，左子树递归返回 p，则整个结果返回 p；
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left == nullptr && right == nullptr) return nullptr;
        else if(left != nullptr && right != nullptr) return root;
        else return left == nullptr ? right : left;
    }
};