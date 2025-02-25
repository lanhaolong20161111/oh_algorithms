class Solution {
  vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> x;
        dfs(nums,x,0);
        return ans;
    }
    void dfs(vector<int> &a,vector<int>&x,int j) {      //回溯算法
        ans.push_back(x);                     //将子集x添加到ans中
        for(int j1=j;j1<a.size();j1++) {        //j1≥j
            x.push_back(a[j1]);
            dfs(a,x,j1+1);
            x.pop_back();
        }
    }
};

