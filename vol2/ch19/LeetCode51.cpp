class Solution {
    vector<vector<string>> ans;             //存放所有的解
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> x;
        for(int i=0;i<n;i++) x.push_back(i);
        dfs(x,n,0);                             //放置0～n-1的皇后
        return ans;
    }
    void dfs(vector<int>&x,int n,int i) {     //回溯算法
        if (i>=n) {                             //所有皇后放置结束
            vector<string> asolution;           //存放一个解
            for(int j=0;j<n;j++) {
                string str(n,'.');              //存放一个皇后位置的字符串
                str[x[j]]='Q';
                asolution.push_back(str);
            }
            ans.push_back(asolution);           //向ans中添加一个解
        }
        else {
            for(int j=i;j<n;j++) {
                swap(x[i],x[j]);                //交换x[i]与x[j]
                if(valid(i,x))                  //剪支
                    dfs(x,n,i+1);
                swap(x[i],x[j]);                //回溯：交换x[i]与x[j]
            }
        }
    }
    bool valid(int i,vector<int>&x) {       //测试(i,x[i])位置是否与前面的皇后不冲突
        if (i==0) return true;
        int k=0;
        while (k<i) {                                       //k=0～i-1是已放置了皇后的行
            if ((x[k]==x[i]) || (abs(x[k]-x[i])==abs(k-i))) 
                return false;                                   //(i,x[i])与皇后k有冲突
            k++;
        }
        return true;
    }
};

