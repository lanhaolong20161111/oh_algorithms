class Solution {
    const int INF=1005;
    vector<vector<int>> A,path;
public:
    int findShortestCycle(int n,vector<vector<int>>& edges) {
        auto M=vector<vector<int>>(n,vector<int>(n,INF));
        for(auto e:edges) {
            int a=e[0],b=e[1];
            M[a][b]=M[b][a]=1;
        }
      vector<vector<int>> A=M;
      int ans=INF;
      for(int k=0;k<n;++k) { 
          for(int i=0;i<k;++i) {				//求ans
              for(int j=i+1;j<k;++j)
                  ans=min(ans,A[i][j]+M[j][k]+M[k][i]);
          }
          for(int i=0;i<n;++i) {				//常规Floyd部分
              for(int j=0;j<n;++j)
                  A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
          }
      }
      if(ans>=INF) return -1;
      return ans;
    }
};

