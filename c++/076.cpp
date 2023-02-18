class Solution {
/*
滑动窗口的标准解题方式：
第一步使得窗口包含子串，
第二步使得窗口再次不包含子串
第三部重复上述一二步骤，记录找的最小的一个子串。

[c++实现](https://leetcode.cn/problems/minimum-window-substring/solution/leetcode-76-zui-xiao-fu-gai-zi-chuan-cja-lmqz/#:~:text=%E6%98%AF%20O(n)%E3%80%82-,2%E3%80%81c%2B%2B%E4%BB%A3%E7%A0%81,-class%20Solution%20%7B)
关键：
* 用两个哈希表维护：字符串t的字符 ht，窗口内的字符 hs
* 窗口为  [ j, i ]，（左右均闭）
* 变量 cnt 维护窗口中满足要求的字符总数（不超过 t）
* 收缩过程：i 一直向右扩展；当 j 指向的字符在窗口中的数量 > t 中数量时，j 向右收缩，同时窗口中字符 j 数量 -1；当窗口中满足要求的字符数量 cnt==len(t)，记录下当前子串，并判断是否为当前最小子串
*/

public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht;
        for (auto c: t) ht[c] ++ ;
        string res;
        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); i ++ ) {
            hs[s[i]] ++ ;
            if (hs[s[i]] <= ht[s[i]]) cnt ++ ;

            while (hs[s[j]] > ht[s[j]]) hs[s[j ++ ]] -- ;
            if (cnt == t.size()) {
                if (res.empty() || i - j + 1 < res.size())
                    res = s.substr(j, i - j + 1);
            }
        }
        return res;
    }
};
