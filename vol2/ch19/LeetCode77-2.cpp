class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> x;
        dfs(n,k,x,1);
        return ans;
    }
    void dfs(int n,int k,vector<int>&x,int j)  {			//ªÿÀ›À„∑®
        if(x.size()==k)
            ans.push_back(x);
        else {
            for(int j1=j;j1<=n;j1++) {
                x.push_back(j1);
                dfs(n,k,x,j1+1);
                x.pop_back();
            }
        }
    }
};

