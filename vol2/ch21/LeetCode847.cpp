class Solution {
    const int INF=0x3f3f3f3f;
    vector<vector<int>> A;
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        A=vector<vector<int>>(n,vector<int>(n,INF));
        for(int i=0;i<n;i++) {      //建立邻接矩阵A
            for(int j:graph[i]) A[i][j]=1;
        }
        Floyd();
        int m=1<<n;           //总的状态数
        vector<vector<int>> dp=vector<vector<int>>(m,vector<int>(n,INF));
        for (int i=0;i<n;i++) dp[1<<i][i]=0;
        for (int state=0;state<m;state++) { //枚举所有的state
            for (int i=0;i<n;i++) {     			//枚举state中已访问的顶点i
                if(!inset(state,i)) continue;  //顶点i不在state中时跳过
                for(int j=0;j<n;j++) {      //枚举state中尚未访问过的顶点j
                    if (inset(state,j)) continue;   //顶点j在state中时跳过
                    int state1=addj(state,j);
                    dp[state1][j]=min(dp[state1][j],dp[state][i]+A[i][j]);
                }
            }
        }
        int ans=INF;
        for (int i=0;i<n;i++)
            ans=min(ans,dp[m-1][i]);
        return ans;
    }
    bool inset(int state,int j) {        //判断顶点j是否在state中
        return (state & (1<<j))!=0;
    }
    int addj(int state,int j) {             //在state添加顶点j
        return state | (1<<j);
    }

    void Floyd() {
        int n=A.size();
        for(int k=0;k<n;k++) {
            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++)
                    A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
            }
        }
    }
};

