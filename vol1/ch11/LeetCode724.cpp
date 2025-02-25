class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        unordered_map<int,int> hmap;
        int ans=0;
        for(int i1=0;i1<m;i1++) {
            vector<int> colsum(n,0);
            for(int i2=i1;i2<m;i2++) {
                hmap[0]=1;						//一维前缀和数组(方式二)
                int cursum=0;
                for(int j=0;j<n;j++) {
                    colsum[j]+=matrix[i2][j];
                    cursum+=colsum[j];
                    ans+=hmap[cursum-target];
                    hmap[cursum]++;
                }
                hmap.clear();
            }
        }
        return ans;
    }
};

