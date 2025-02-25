class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum3(int k,int n) {
        int cnt=0;
        vector<int> x;
        dfs(n,k,0,x,cnt,1);                             //i从1开始
        return ans;
    }
    void dfs(int n,int k,int cs,vector<int>& x,int cnt,int i){      //回溯算法
        if (i>=10) {                                        //找到一个叶子结点
            if (cs==n && cnt==k)                        //找到一个满足条件的解
                ans.push_back(x);
        }
        else {                                  //没有到达叶子结点
            x.push_back(i);                     //选取整数i 
            cnt++;
            dfs(n,k,cs+i,x,cnt,i+1);
            cnt--;                              //回溯
            x.pop_back();
            dfs(n,k,cs,x,cnt,i+1);                  //不选取整数i
        }
    }
};

