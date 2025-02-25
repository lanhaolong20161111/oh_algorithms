class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum3(int k,int n) {
        vector<int> x(k);
        dfs(n,k,0,x,0);             //i从0开始
        return ans;
    }
    void dfs(int n,int k,int cs,vector<int>& x,int i){  //回溯算法
        if (i>=k) {                         //找到一个叶子结点
            if (cs==n)                      //找到一个满足条件的解
                ans.push_back(x);
        }
        else {                                  //没有到达叶子结点
            for(int j=1;j<=9;j++) {
                if(i>0 && j<=x[i-1]) continue;
                x[i]=j;
                dfs(n,k,cs+j,x,i+1);
            }
        }
    }
};

