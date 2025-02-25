class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> x;
        dfs(nums,x,0);
        return ans;
    }
    void dfs(vector<int>&a,vector<int>&x,int i) {   //回溯算法
        if (i>=a.size())                            //到达一个叶子结点
            ans.push_back(x);                     //将子集x添加到ans中
        else {
            x.push_back(a[i]);                      //选择a[i]
            dfs(a,x,i+1);
            x.pop_back();                       //回溯
            dfs(a,x,i+1);               //不选择a[i]
        }
    }
};

