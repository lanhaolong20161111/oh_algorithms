class Solution {
    vector<bool> visited;
    vector<bool> safe;
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> ans;
        safe=vector<bool>(n,false);             //初始化safe
        for(int i=0;i<n;i++) {                  //试探每个顶点i
            visited=vector<bool>(n,false);      //初始化visited
            if(dfs(graph,i)) ans.push_back(i);
        }
        return ans;
    }
    bool dfs(vector<vector<int>>&graph,int i) {    //从i出发DFS是否找到终点
        if(safe[i]) return true;                    //i是安全的，返回true
        if(visited[i]) return false;                //i访问过，返回false
        if(graph[i].empty()) {                      //到达终点i（没有出边）
            safe[i]=true;                           //i是安全的
            return true;                            //返回true
        }
        visited[i]=true;
        for(int j:graph[i]) {                       //遍历i的每个相邻点j
            if (!dfs(graph,j))                      //任意一边不满足返回假
                return false;
        }
        safe[i]=true;                               //i是安全的
        return true;                                //返回true
    }
};

