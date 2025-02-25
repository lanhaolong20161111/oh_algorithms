class Solution {
    vector<vector<int>> adj;            //邻接表
    vector<vector<bool>> path;                  //path[i][j]表示i到j是否有路径
public:
    vector<bool> checkIfPrerequisite(int n,vector<vector<int>>&prereqs,vector<vector<int>>&ques) {
        adj=vector<vector<int>>(n);
        path=vector<vector<bool>>(n,vector<bool>(n,false));
        for (int i=0;i<prereqs.size();i++) {    //由列表创建邻接表
            int a=prereqs[i][0];                //[a,b]表示a是b的先修课程
            int b=prereqs[i][1];
            adj[a].push_back(b);                //用<a,b>表示即先修a,再修b
        }
        for(int i=0;i<n;i++)
            bfs(n,i);
        vector<bool> ans(ques.size()); 
        for (int i=0;i<ques.size();i++)
            ans[i]=path[ques[i][0]][ques[i][1]];
        return ans;
    }
    void bfs(int n,int i) {                                   //广度优先遍历算法
        queue<int> qu;                              //定义一个队列qu
        path[i][i]=true;                            //自己到自己有路径
        qu.push(i);                                 //课程i进队
        while (!qu.empty()) {                       //队不空循环
            int cnt=qu.size();
            for(int j=0;j<cnt;j++) {
                int u=qu.front(); qu.pop();         //出队课程u
                for(int v:adj[u]) {                 //考虑课程u的出边课程v
                    if(path[i][v]) continue;
                    path[i][v]=true;                //表示课程i到v有路径
                    qu.push(v);                     //课程v进队
                }
            }
        }
    }
};

