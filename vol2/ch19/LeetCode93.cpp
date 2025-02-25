class Solution {
    vector<string> ans;
    int x[4];
public:
    vector<string> restoreIpAddresses(string s) {
        dfs(s,0,0);
        return ans;
    }
    void dfs(string&s,int cnt,int i) {     //回溯算法
        int n=s.size();
        if((n-i>(4-cnt)*3) || (n-i<(4-cnt))) //剪支
            return;
        if(i==n) {                      //到达一个叶子结点
            if(cnt==4) {                //找到一个解
            string tmp="";                  //将x转换为字符串
            for(int j=0;j<4;j++) {
                tmp+=to_string(x[j]);
                if(j!=3) tmp+='.';
             }
             ans.push_back(tmp);
            }
        }
        else {
        if (s[i]=='0') {        //不能有前导零
           x[cnt]=0;            //若当前为'0'，则这段IP地址只能为0
           dfs(s,cnt+1,i+1);
        }
        int d=0;
        for (int j=i;j<min(i+3,n);j++) {    //试探j的每个可能的位置
            d=d*10+(s[j]-'0');   
            if (d>0 && d<=255) {    //剪支
                x[cnt]=d;
                dfs(s,cnt+1,j+1);
            }
            else return;            //无效d时回溯
        }
        }
    }
};

