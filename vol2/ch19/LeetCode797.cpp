class Solution {
    vector<vector<int>> ans;                //存放所有路径
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>x;
        x.push_back(0);
        dfs(graph,x);
        return ans;
    }
    void dfs(vector<vector<int>>& graph,vector<int>&x) {    //回溯算法
        if(x.back()==graph.size()-1)
            ans.push_back(x);
        else {
            for(int j:graph[x.back()]) {			//扩展
                x.push_back(j);
                dfs(graph,x);
                x.pop_back();
            }
        }
    }
};

