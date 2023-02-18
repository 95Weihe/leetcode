class Solution {
/*
动态规划：
dp[i]：表示字符串 s 前 i 个字符 s[0...i-1] 是否能被空格拆分成若干个字典中出现的单词

状态：需要枚举 s[0...i-1] 中的分割点 j ，看 s[0...j-1] 组成的字符串 s1 和 s[j...i-1]组成的 s2 是否都合法，若均合法，则 s[0...i-1] 合法，否则不合法
方程：dp[i] = dp[j] && check(s[j...i-1])

初始化：dp[0] = true; 表示空串合法

其中，check() 可用字典树实现

*/
    struct Tire
    {
        vector<Tire*> children;
        bool IsEnd;
        Tire():children(26),IsEnd(false){}//初始化
    };
     void Insert(Tire*& root,vector<string>& dictionary)//插入，构造字典树
    {
        for(int i=0;i<dictionary.size();i++)
        {
            string temp=dictionary[i];
            Tire* node=root;
            for(int j=0;j<temp.size();j++)
            {
                if(node->children[temp[j]-'a']==NULL)
                {
                    node->children[temp[j]-'a']=new Tire();
                }
                node=node->children[temp[j]-'a'];
            }
            node->IsEnd=true;
        }
    }
    bool startsWith(Tire* root,string word)//找前缀字符串
    {
        // string res;
        Tire* node=root;
        for(int i=0;i<word.size();i++){
            if(node->children[word[i]-'a']==NULL)//第一个字母都不符合
                return 0;
            // res+=word[i];
            node=node->children[word[i]-'a'];
        }
        if(node->IsEnd==true){
            return 1;
        }
        return 0;//说明dictionnary中的单词word[i]长
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Tire* root = new Tire();
        Insert(root,wordDict);
        
        auto dp = vector<bool>(s.size()+1);
        dp[0] = 1;
        for(int i=1; i<=s.size(); i++){
            for(int j=0; j<i; j++){
                if(dp[j] && startsWith(root,s.substr(j,i-j))){
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};