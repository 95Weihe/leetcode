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
//[递归思路](https://blog.csdn.net/qq_35812205/article/details/115792634)
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->left);    //递归将左子树变为链表
        TreeNode* right = root->right;  //暂存右子树
        root->right = root->left;   //将左链表变为右子树
        root->left = nullptr;
        while (root->right != nullptr) {    //找到当前树的最右边节点
            root = root->right;
        }
        flatten(right); //递归将右子树变为链表
        root->right = right;    //将右子树链表接到树的最右边节点之后
    }
};