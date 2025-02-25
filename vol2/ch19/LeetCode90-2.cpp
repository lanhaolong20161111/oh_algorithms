class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)  {
        sort(nums.begin(),nums.end());
        vector<int> x;          //存放一个子集
        dfs(nums,x,0);
        return ans;
    }
    void dfs(vector<int>& a, vector<int> &x,int j)  {	//回溯算法
        ans.push_back(x);
        for(int j1=j;j1<a.size();j1++)  {
            if(j1>j && a[j1-1]==a[j1]) continue;
            x.push_back(a[j1]);
            dfs(a,x,j1+1);
            x.pop_back();
        }
    }
};

