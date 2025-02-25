class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> revadj(n);//反图邻接表
        vector<int> degree(n,0);               //存放反图的入度
        vector<int> ans;
        queue<int> qu;                      //对反图进行拓扑排序
        for(int i=0;i<n;i++) {
            degree[i]=graph[i].size();
            if(degree[i]==0) qu.push(i);      //入度为0的顶点进队
            for(int j:graph[i])
                revadj[j].push_back(i);
        }
        while(!qu.empty()) {                //分层次的层次遍历
            int cnt=qu.size();
            for(int i=0;i<cnt;i++) {
                int u=qu.front();qu.pop();
                ans.push_back(u);
                for(int v:revadj[u]) {
                    degree[v]-=1;
                    if(degree[v]==0) qu.push(v);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

