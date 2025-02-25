class Solution {
    vector<int> ans;
    vector<int> used;       //used[i]表示i是否使用过
    int cnt=0;
public:
    string getPermutation(int n,int k) {
        vector<int> x(n);
        used=vector<int>(n+1,0);
        dfs(x,0,k);
        string ret="";              //将ans转换为字符串ret
        for(int e:ans) ret+=to_string(e);
        return ret; 
    }
    bool dfs(vector<int>&x,int i,int k) {   //回溯算法
        int n=x.size();
        if (i>=n) {
            cnt++;                          //累计找到的排列个数
            if(cnt==k) {                    //找到第k个排列
                ans=x;
                return true;
            }
        }
        else {
            for(int j=1;j<=n;j++) {
                if(used[j]) continue;                   //剪支：跳过已经使用过的j
                x[i]=j;
                used[j]=1;                              //选择j
                if(dfs(x,i+1,k))
                    return true;
                used[j]=0;                              //回溯
                x[i]=-1;
            }
        }
        return false;
    }
};

