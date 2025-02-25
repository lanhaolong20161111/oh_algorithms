class Solution {
    set<vector<int>> s;						//s为STL集合容器，用于除重
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> x;
        dfs(nums,x,0);
        vector<vector<int>> ans;					//将集合s中元素添加到ans中
        for(auto e: s)
            ans.push_back(e);
        return ans;
    }
    void dfs(vector<int> &a,vector<int>&x,int i) {              //回溯算法
        if (i>=a.size())                                   //到达一个叶子结点
            s.insert(x);
        else {
            x.push_back(a[i]);                         //选择a[i]
            dfs(a,x,i+1);
            x.pop_back();
            dfs(a,x,i+1);                         //不选择a[i]
        }
    }
};

