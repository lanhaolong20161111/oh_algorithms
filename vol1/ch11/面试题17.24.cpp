class Solution {
    const int INF=0x3f3f3f3f;
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    vector<vector<int>> presum(m+1,vector<int>(n+1,0));
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            presum[i][j]=presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1]+matrix[i-1][j-1];
        }
    }
    vector<int> ans;
    int maxsum=-INF;
    for (int i1=0;i1<m;i1++) {
        for (int i2=i1;i2<m;i2++) {
            int cursum=0,j1=0;
            for (int j2=0;j2<n;j2++) {
                cursum=presum[i2+1][j2+1]+presum[i1][j1]-presum[i2+1][j1]-presum[i1][j2+1];
                if (cursum>maxsum) {
                    maxsum=cursum;
                    ans={i1,j1,i2,j2};
                }
                if (cursum<0) j1=j2+1;			//cursum<0时子矩阵左列j1从j2+1开始
            }
        }
    }
    return ans;
    }
};

