class Solution {
    public boolean isMatch(String s, String p) {
        //此处为length+1的目的是放入一个额外的为空的字符情况，以便于判断当*时，添加的字符情况
        boolean table[][]=new boolean[s.length()+1][p.length()+1];
        table[0][0]=true;
        for(int i =1;i<table[0].length;i++){
            char ch=p.charAt(i-1);
            if(i>1){
                //若ch=='*'，则看同一行内回退两格的boolean值：
                //（因为相当于若回退两格为true，即在选择添加该字符时可以选择数量为0（因为是'*'））
                if(ch=='*'){
                    table[0][i]=table[0][i-2];
                }
                //因为第0行的s字符为空，所以和除了*以外的都不匹配，直接false
                else table[0][i]=false;
            }
            else {
                //如果填第一个空格，且字符为*，则赋值为true（因为*的匹配可以选择0个字符）
                if(ch=='*') table[0][i]=true;
            }
        }
        //接下来按照行优先的顺序填充表格
        for(int j =1;j<table.length;j++){
            char ch01=s.charAt(j-1);
            for(int h =1;h<table[j].length;h++){
                char ch02=p.charAt(h-1);
                //如果行和列对应的字符相等 || 列的字符为'.'，则当前位置的值由左斜上方的值确定
                if(ch02==ch01||ch02=='.'){
                    table[j][h]=table[j-1][h-1];
                }
                //如果列的字符为'*'
                else if(ch02=='*'){
                    if(h>1){
                        //按照规则，先在同一行回退两格，若该值为true则直接赋值true
                        if(table[j][h-2]==true) table[j][h]=true;
                        else {
                            //若不为true，则比较当前行的字符（s里的）与当前列-1的字符（p里的）是否相等
                            char prev=p.charAt(h-2);
                            //若相等 || 当前列-1的字符（p里的）为'.'，将当前位置上方的值赋给当前位置
                            if(ch01==prev||prev=='.') table[j][h]=table[j-1][h];
                        }
                    }

                }
            }
        }
        //返回table表的最右下方元素，即为整个字符串的匹配结果
        return table[s.length()][p.length()];
    }
}