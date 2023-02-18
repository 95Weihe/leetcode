class Solution {
    /*我的思路：
    1、people按[i][1]排序
    2、记录res中大于[i][0]的个数，记录到个数等于[i][1]为止，由此处开始将[i](类似直接插入排序)顺序插入res中
    3、由于涉及频繁在中间插入，所以先用单链表list模拟此过程
    */
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(),people.end(),[](vector<int> a,vector<int> b){return a[1]<b[1];});
        forward_list<int> list;
        list.push_front(0);
        for(int i=1; i<people.size(); i++){
            auto x = people[i];
            int k=x[1];
            forward_list<int>::iterator pre=list.end(),p;
            for(p=list.begin(); p!=list.end(); pre=p,++p){
                auto q = people[*p][0];
                if(k>0&&q>=x[0]){
                    k--;
                }else if(!k&&q>=x[0]){
                    if(pre!=list.end())
                        list.insert_after(pre,i);
                    else list.push_front(i);
                    break;
                }
            }
            if(p==list.end()){
                list.insert_after(pre,i);
            }
        }
        
        for(auto p=list.begin(); p!=list.end(); ++p){
            res.push_back(people[*p]);
        }
            
        return res;
    }
};