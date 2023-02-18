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
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        //逆中序的和
        reverse_inOrder(root,sum);
        return root;
    }

    //sum即当前遍历到的顶点和
    void reverse_inOrder(TreeNode* t,int& sum){
        if(t){
            reverse_inOrder(t->right,sum);
            t->val += sum;
            sum = t->val;
            reverse_inOrder(t->left,sum);
        }
    }
};