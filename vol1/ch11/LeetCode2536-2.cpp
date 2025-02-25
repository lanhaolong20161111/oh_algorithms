class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n+1,vector<int>(n+1));
        for(int i=0;i<queries.size();i++) {
            int r1=queries[i][0],c1=queries[i][1];
            int r2=queries[i][2],c2=queries[i][3];
            diff[r1][c1]++;
            diff[r2+1][c2+1]++;
            diff[r1][c2+1]--;
            diff[r2+1][c1]--;
        }
        vector<vector<int>> ans(n,vector<int>(n));
        ans[0][0]=diff[0][0];
        for(int i=1;i<n;i++) {
            diff[i][0]+=diff[i-1][0];
            ans[i][0]=diff[i][0];
        }
        for(int j=1;j<n;j++) {
            diff[0][j]+=diff[0][j-1];
            ans[0][j]=diff[0][j];
        }
        for(int i=1;i<n;i++) {
            for(int j=1;j<n;j++) {
                diff[i][j]+=diff[i-1][j]+diff[i][j-1]-diff[i-1][j-1];
                ans[i][j]=diff[i][j];
            }
        }
        return ans;
    }
};

