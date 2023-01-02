class Solution {
/*
  给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
*/
    public int lengthOfLongestSubstring(String s) {
        // 记录字符上一次出现的位置
        int[] last = new int[128];
        int len = s.length();
        int start = 0;
        int res = 0;
        for(int i = 0; i < len; i++){
            int index = s.charAt(i);
            start = Math.max(start, last[index]);
            res   = Math.max(res, i - last[index] + 1);
            last[index] = i + 1;
        }
        return res;
    }
}