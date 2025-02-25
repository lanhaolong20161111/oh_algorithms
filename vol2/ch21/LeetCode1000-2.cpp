class Solution {
    const int INF=0x3f3f3f3f;                               //��ʾ��
public:
    int mergeStones(vector<int>& stones,int K) {
        int n=stones.size();
        if ((n-1)%(K-1)!=0) return -1;
        vector<vector<int>> dp(n,vector<int>(n,INF));
        for(int i=0;i<n;i++)
            dp[i][i]=0;
        vector<int> presum(n+1,0);                 		 //���ǰ׺��
        for (int i=1;i<=n;i++)                              //��ǰ׺��
            presum[i]=presum[i-1]+stones[i-1]; 
        for(int length=2;length<=n;length++) {
            for (int i=0;i<n-length+1;i++) {
                int j=i+length-1;
                for (int m=i;m<j;m+=K-1)
                    dp[i][j]=min(dp[i][j],dp[i][m]+dp[m+1][j]);
                if ((length-1)%(K-1)==0)  //��������ܹ��ϲ���ϲ�
                    dp[i][j]+=presum[j+1]-presum[i];
            }
        }
        return dp[0][n-1];
    }
};

