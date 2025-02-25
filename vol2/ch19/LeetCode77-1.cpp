class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> x;
        dfs(n,k,0,x,1);
        return ans;
    }
    void dfs(int n,int k,int cnt,vector<int>&x,int i) {			//回溯算法
        if(i>n) {
            if(cnt==k)
                ans.push_back(x);
        }
        else {
            x.push_back(i);             //选择i
            dfs(n,k,cnt+1,x,i+1);
            x.pop_back();
            dfs(n,k,cnt,x,i+1);         //不选择i
        }
    }
};

