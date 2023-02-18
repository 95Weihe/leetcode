class Solution {
public:
    string decodeString(string s) {
        int i=0;
        return recur(s,i);
    }

    string recur(string s, int &i){
        string t="";
        for(; i<s.size(); i++){
            if(isdigit(s[i])){
                int d = 0;
                while(isdigit(s[i]))
                    d = d*10+s[i++]-'0';
                string st = recur(s,++i);
                while(d--){
                    t+=st;
                }
            }else if(s[i]==']'){
                break;
            }else{
                t+=s[i];
            }
        }
        return t;
    }
};