class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> presum(m+1,vector<int>(n+1));
        for (int i=1;i<=m;i++) {
            for (int j=1;j<=n;j++) {
                presum[i][j]=presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1]+matrix[i-1][j-1];
            }
        }
        int ans=0;
        for (int i1=1;i1<=m;i1++) {
            for (int i2=i1;i2<=m;i2++) {
                unordered_map<int,int> hmap;
                for (int j=1;j<=n;j++) {
                    int cursum=presum[i2][j]-presum[i1-1][j];
                    if (cursum==target) ans++;
                    if (hmap.count(cursum-target))
                        ans+=hmap[cursum-target];
                    hmap[cursum]++;
                }
            }
        }
        return ans;
    }
};

