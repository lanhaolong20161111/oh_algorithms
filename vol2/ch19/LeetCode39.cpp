class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates,int target) {
        vector<int> x;
        dfs(candidates,target,x,0);                         //i从0开始
        return ans;
    }
    void dfs(vector<int>&a,int rt,vector<int>& x,int i) {   //回溯算法
        if(rt==0) {                     //找到一个解
            ans.push_back(x);
        }
        else if(i<a.size()) {           //a尚未遍历完毕
            dfs(a,rt,x,i+1);            //不选择a[i]
            if(a[i]<=rt) {              //不超重时选择a[i]
                x.push_back(a[i]);
                dfs(a,rt-a[i],x,i);
                x.pop_back();
            }
        }
    }
};

