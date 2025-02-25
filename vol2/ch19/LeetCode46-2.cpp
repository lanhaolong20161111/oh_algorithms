class Solution {
    vector<vector<int>> ans;        //存放答案
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> x=nums;
        dfs(x,0);
        return ans;
    }
    void dfs(vector<int>&x,int i) {     //回溯算法
        int n=x.size();
        if (i>=n)
         ans.push_back(x);
        else {
            for(int j=i;j<n;j++) {
                swap(x[i],x[j]);        //交换x[i]与x[j]
                dfs(x,i+1);
                swap(x[i],x[j]);        //回溯：交换x[i]与x[j]
            }
        }
    }
};

