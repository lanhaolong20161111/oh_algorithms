class Solution {
    vector<vector<int>> ans;        //存放答案
    vector<int> used;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        used=vector<int>(n,0);
        vector<int> x;
        dfs(nums,x,0);
        return ans;
    }
    void dfs(vector<int>&a,vector<int>&x,int i) {   //回溯算法
        int n=a.size();
        if (i>=n)
            ans.push_back(x);
        else {
            for(int j=0;j<n;j++) {
                if(used[j]) continue;               //剪支：跳过已经使用过的a[j]
                x.push_back(a[j]);
                used[j]=1;                          //选择a[j]
                dfs(a,x,i+1);                       //转向解空间树的下一层
                used[j]=0;                          //回溯
                x.pop_back();
            }
        }
    }
};

