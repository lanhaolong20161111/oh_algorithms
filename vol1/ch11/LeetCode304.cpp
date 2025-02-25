class NumMatrix {
private:
    vector<vector<int>> presum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        presum.resize(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++)
                presum[i][j]=presum[i][j-1]+presum[i-1][j]-presum[i-1][j-1]+matrix[i-1][j-1];
        }
    }
    
    int sumRegion(int row1,int col1,int row2,int col2) {
        return presum[row2+1][col2+1]-presum[row1][col2+1]-presum[row2+1][col1]+presum[row1][col1];
    }
};

