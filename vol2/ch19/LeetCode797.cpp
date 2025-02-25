class Solution {
    vector<vector<int>> ans;                //�������·��
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>x;
        x.push_back(0);
        dfs(graph,x);
        return ans;
    }
    void dfs(vector<vector<int>>& graph,vector<int>&x) {    //�����㷨
        if(x.back()==graph.size()-1)
            ans.push_back(x);
        else {
            for(int j:graph[x.back()]) {			//��չ
                x.push_back(j);
                dfs(graph,x);
                x.pop_back();
            }
        }
    }
};

