class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(!n) return tasks.size();
        /*
        思路：wst+Q模拟滑动窗口（wst存储窗口内的有效字符，Q按顺序存储窗口内的字符包括'*'（‘待命’））
        1、哈希表tkmp对tasks计数，转换为vmp，方便对value排序(保证从vmp中按value值从大到小取元素)
        2、初始化窗口（大小为n+1），使窗口内含不同字符，不足用'*'代替
        3、每次Q出一个元素，然后从vmp中去一个不同于wst的元素进队列，否则使‘*’进队
        */
        unordered_map<char,int> tkmp;
        vector<pair<char,int>> vmp;
        unordered_set<char> wst;
        queue<char> Q;
        int res=0, len=tasks.size();

        //计数
        for(auto x:tasks){
            tkmp[x]+=1;
        }
        for (unordered_map<char, int>::iterator it = tkmp.begin(); it != tkmp.end(); it++)
            vmp.push_back(make_pair(it->first, it->second));

        sort(vmp.begin(), vmp.end(),[](pair<char,int> a,pair<char,int> b){return a.second>b.second;});

        //初始化窗口
        for(auto it=vmp.begin(); it!=vmp.end()&&wst.size()<n+1; ++it){
            if(wst.find(it->first)==wst.end()){
                wst.insert(it->first);
                Q.push(it->first);
                it->second--;
                len--;
                res++;
            }
        }
        while(Q.size()<n+1 && len){
            Q.push('*');
            res++;
        }
        
        while(len){
            char q=Q.front();
            Q.pop();
            if(q!='*'){
                wst.erase(q);
            }
                
            sort(vmp.begin(),vmp.end(),[](pair<char,int> a,pair<char,int> b){return a.second>b.second;});
            auto it=vmp.begin();
            for(; it!=vmp.end(); ++it){
                char c = it->first;
                if(it->second>0 && wst.find(c)==wst.end()){
                    wst.insert(c);
                    Q.push(c);
                    it->second--;
                    len--;
                    break;
                }
            }
            if(it==vmp.end()){
                Q.push('*');
            }
            res++;
        }

        return res;
    }
};