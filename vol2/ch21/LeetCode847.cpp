class Solution {
    const int INF=0x3f3f3f3f;
    vector<vector<int>> A;
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        A=vector<vector<int>>(n,vector<int>(n,INF));
        for(int i=0;i<n;i++) {      //�����ڽӾ���A
            for(int j:graph[i]) A[i][j]=1;
        }
        Floyd();
        int m=1<<n;           //�ܵ�״̬��
        vector<vector<int>> dp=vector<vector<int>>(m,vector<int>(n,INF));
        for (int i=0;i<n;i++) dp[1<<i][i]=0;
        for (int state=0;state<m;state++) { //ö�����е�state
            for (int i=0;i<n;i++) {     			//ö��state���ѷ��ʵĶ���i
                if(!inset(state,i)) continue;  //����i����state��ʱ����
                for(int j=0;j<n;j++) {      //ö��state����δ���ʹ��Ķ���j
                    if (inset(state,j)) continue;   //����j��state��ʱ����
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
    bool inset(int state,int j) {        //�ж϶���j�Ƿ���state��
        return (state & (1<<j))!=0;
    }
    int addj(int state,int j) {             //��state��Ӷ���j
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

