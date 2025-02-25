class Solution {
public:
    string decodeString(string s) {
        int i=0;                            //i从0开始遍历s
        return unfold(s,i);
    }
    string unfold(string&s,int& i) {       //递归算法
        int n=s.size();
        string ans="";                      //存放字符串解码 
        while(i<n) {                        //遍历s
            if(isalpha(s[i])) {             //遇到字母
                ans+=s[i++];                //提取连续的字母串
            }
            else if(isdigit(s[i])) {        //遇到数字
                int k=0;
                while(i<n && isdigit(s[i])) {
                    k=10*k+(s[i++]-'0');    //遇到数字，将连续的数字符转换为整数k
                }
                i++;                        //跳过后面的'['
                string d=unfold(s,i);       //递归展开后续的(e)得到d
                while(k--) {                  //连接d字符串k次
                    ans+=d;
                }
            }
            else {                          //遇到']'
                i++;                        //跳过']'
                return ans;                 //返回该问题的解
            }
        }
        return ans;
    }
};

