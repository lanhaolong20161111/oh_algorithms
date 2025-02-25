class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n,vector<vector<int>>&queries) {
        vector<vector<int>> diff(n,vector<int>(n,0));
        for(int p=0;p<queries.size();p++) {
            int r1=queries[p][0],c1=queries[p][1];
            int r2=queries[p][2],c2=queries[p][3];
            for(int i=r1;i<=r2;i++) {
                diff[i][c1]+=1;
                if(c2+1<n) diff[i][c2+1]-=1;
            }
        }
        vector<vector<int>> ans(n,vector<int>(n,0)); 
        for(int i=0;i<n;i++)
            ans[i][0]=diff[i][0];
        for(int i=0;i<n;i++) {
            for(int j=1;j<n;j++)
                ans[i][j]=ans[i][j-1]+diff[i][j];
        }
        return ans;
    }
};

