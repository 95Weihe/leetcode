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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = index_x(inorder, preorder[0]);
        int n = preorder.size();
        TreeNode* t = new TreeNode(preorder[0]);
        if(i>0)
            build(t->left,preorder,inorder,1,i,0,i-1);
        if(i<n-1)
            build(t->right,preorder,inorder,i+1,n-1,i+1,n-1);
        return t;
    }

    void build(TreeNode*& t, vector<int>& pre, vector<int>& in, int l1, int r1, int l2, int r2){
        t = new TreeNode(pre[l1]);
        int i = index_x(in,pre[l1]);
        int len = i-l2;
        if(i-1>=l2)
            build(t->left,pre,in,l1+1,len+l1,l2,i-1);
        if(r2>=i+1)
            build(t->right,pre,in,l1+len+1,r1,i+1,r2);
    }

    int index_x(vector<int>& v, int x){
        return find(v.begin(),v.end(),x)-v.begin();
    }
};