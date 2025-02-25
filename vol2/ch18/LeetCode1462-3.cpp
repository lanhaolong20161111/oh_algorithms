class Solution {
    vector<vector<int>> adj;            //邻接表
    vector<vector<bool>> path;          //path[i][j]表示i到j是否有路径
    vector<int> degree;                 //顶点的入度
public:
    vector<bool> checkIfPrerequisite(int n,vector<vector<int>>&prereqs,vector<vector<int>>&ques) {
        adj=vector<vector<int>>(n);
        path=vector<vector<bool>>(n,vector<bool>(n,false));
        degree=vector<int>(n,0);
        for (int i=0;i<prereqs.size();i++) {    //由列表创建邻接表
            int a=prereqs[i][0];                //[a,b]表示a是b的先修课程
            int b=prereqs[i][1];
            adj[a].push_back(b);                //用<a,b>表示即先修a,再修b
            degree[b]++;                        //b的入度增1
        }
        topsort(n);
        vector<bool> ans(ques.size()); 
        for (int i=0;i<ques.size();i++)
            ans[i]=path[ques[i][0]][ques[i][1]];
        return ans;
    }
    void topsort(int n) {                //拓扑排序
        stack<int> st;
        for(int i=0;i<n;i++) {         //入度为0的课程进栈
            if(degree[i]==0) st.push(i);
        }
        while(!st.empty()) {            //栈不空循环
            int i=st.top();st.pop();    //出栈课程i
            for (int j:adj[i]) {        //考虑课程i的出边课程j
                degree[j]--;             //课程k的入度减1
                path[i][j]=true;         //i是j的先修课程
                for(int k=0;k<n;k++) {   //i的先修课程k也是j的先修课程
                    if(path[k][i]) path[k][j]=true;
                }
                if (degree[j]==0) st.push(j);
            }
        }
    }
};

