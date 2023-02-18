/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    //静态变量，用于所有类对象共享，需在类外定义
    //mp 存储树的地址与该节点的对应关系
    static map<string,TreeNode*> mp;
    //前序遍历
    void preOrder(TreeNode* t, vector<TreeNode*>& vs){
        if(t){
            vs.push_back(t);
            preOrder(t->left,vs);
            preOrder(t->right,vs);
        }
    }
    //中序遍历
    void inOrder(TreeNode* t, vector<TreeNode*>& vs){
        if(t){
            inOrder(t->left,vs);
            vs.push_back(t);
            inOrder(t->right,vs);
        }
    }
    //建造二叉树
    TreeNode* buildTree(vector<TreeNode*>& preorder, vector<TreeNode*>& inorder) {
        int i = index_x(inorder, preorder[0]);
        int n = preorder.size();
        TreeNode* t = new TreeNode(preorder[0]->val);
        if(i>0)
            build(t->left,preorder,inorder,1,i,0,i-1);
        if(i<n-1)
            build(t->right,preorder,inorder,i+1,n-1,i+1,n-1);
        return t;
    }
    void build(TreeNode*& t, vector<TreeNode*>& pre, vector<TreeNode*>& in, int l1, int r1, int l2, int r2){
        t = new TreeNode(pre[l1]->val);
        int i = index_x(in,pre[l1]);
        int len = i-l2;
        if(i-1>=l2)
            build(t->left,pre,in,l1+1,len+l1,l2,i-1);
        if(r2>=i+1)
            build(t->right,pre,in,l1+len+1,r1,i+1,r2);
    }
    int index_x(vector<TreeNode*>& v, TreeNode* x){
        return find(v.begin(),v.end(),x)-v.begin();
    }
    //分割字符串
    vector<string> split(const string &str, char dec){
        int pos=0, start=0;
        vector<string> res;
        while(pos<str.size()){
            while(pos<str.size() && str[pos]==dec){
                pos++;
            }
            start=pos;
            while(pos<str.size() && str[pos]!=dec){
                pos++;
            }
            if(start < str.size()){
                res.emplace_back(str.substr(start,pos-start));
            }
        }
        return res;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        vector<TreeNode*> pre,in;
        preOrder(root,pre);
        inOrder(root,in);
        if(pre.size()==0){
            return res;
        }
        
        for(int i=0; i<pre.size(); i++){
            //将地址变量转为string
            stringstream ss;
            ss << (void *)pre[i];
            if(i<pre.size()-1){
                res.append(ss.str()+",");
            }else res.append(ss.str());
            if(mp.find(ss.str())==mp.end()){
                mp[ss.str()]=pre[i];
            }
        }
        res.append("|");
        for(int i=0; i<in.size(); i++){
            stringstream ss;
            ss << (void *)in[i];
            if(i<in.size()-1){
                res.append(ss.str()+",");
            }else res.append(ss.str());
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return NULL;
        vector<string> arr = split(data,'|');
        vector<string> ps, is;
        ps = split(arr[0],',');
        is = split(arr[1],',');

        vector<TreeNode*> pre, in;
        for(auto& s:ps){
            pre.push_back(mp[s]);
        }
        for(auto& s:is){
            in.push_back(mp[s]);
        }
        return buildTree(pre,in);
    }
};
map<string,TreeNode*> Codec::mp={};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));