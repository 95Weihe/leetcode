/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        map<char,int> mp;
        //滑动窗口，队列同步存储下标，即队列窗口
        map<char,int> wmp;
        queue<int> Q;
        
        int len = p.size();
        for(char x:p)
            mp[x]++;
        for(int i=0; i<s.length(); i++){
            //s[i]在字符串p中
            if(mp[s[i]]>0){
                do{
                    wmp[s[i]]++;
                    Q.push(i);
                    //当前窗口内字符s[i]数量大于p中数量
                    if(wmp[s[i]]>mp[s[i]]){
                        //字符s[i]不在p中，则队列窗口置空；否则将队列窗口出队，直到队头字符等于s[i],且将等于s[i]的队头也出队为止
                        if(mp[s[i]]==0){
                            wmp.clear();
                            Q = queue<int>();
                        }else {
                            int k;
                            while(!Q.empty()&&s[Q.front()]!=s[i]){
                                k = Q.front();
                                Q.pop();
                                wmp[s[k]]--;
                            }
                            if(!Q.empty()){
                                k = Q.front();
                                Q.pop();
                                wmp[s[k]]--;
                            }
                        }
                        break;
                    }else if(wmp[s[i]]==mp[s[i]]&&Q.size()==len){   //队列窗口满足条则记录队头，且将队头出队为下一次匹配准备
                        int k = Q.front();
                        Q.pop();
                        res.push_back(k);
                        wmp[s[k]]--;
                    }
                }while(++i<s.length());
            }
        }
        return res;
    }

};
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