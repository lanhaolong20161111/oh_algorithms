class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> x;
        dfs(nums,x,0);
        return ans;
    }
    void dfs(vector<int>&a,vector<int>&x,int j) {			//回溯算法
        if(x.size()>1){
            ans.push_back(x);
        }
        unordered_set<int> used;                    //实现同层除重
        for(int j1=j;j1<a.size();j1++) {
            if(!x.empty() && a[j1]<x.back()) continue;  //约束剪支
        if(used.count(a[j1])==1) continue;                  //除重剪支
            used.insert(a[j1]);
            x.push_back(a[j1]);
            dfs(a,x,j1+1);
            x.pop_back();
            //此处不能包含used.erase(a[j1]);为什么？
        }
    }
};

