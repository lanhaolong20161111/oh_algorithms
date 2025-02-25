class Solution {
    const int INF=0x3f3f3f3f;                               //��ʾ��
public:
    int mergeStones(vector<int>& stones,int K) {
        int n=stones.size();
        if ((n-1)%(K-1)!=0) return -1;
        int dp[n+1][n+1][K+1];
        memset(dp,0x3f,sizeof(dp));
        for(int i=0;i<=n;i++)
            dp[i][i][1]=0;
        vector<int> presum(n+1,0);              //���ǰ׺��
        presum[0]=0;
        for(int i=1;i<=n;i++)                  //��ǰ׺��
            presum[i]=presum[i-1]+stones[i-1]; 
        for(int length=2;length<=n;length++) { 
            for(int i=0;i<n-length+1;i++) {     //ö������[i,j]
                int j=i+length-1;
                for (int k=1;k<=K;k++) {                        //ö�ٶ���k
                    for (int m=i;m<j;m++)                   //ö�ٷֽ��m
                        dp[i][j][k]=min(dp[i][j][k],dp[i][m][1]+dp[m+1][j][k-1]);
                }
                dp[i][j][1]=dp[i][j][K]+presum[j+1]-presum[i]; //����[i,j]��K�Ѻϲ���һ��
            }
        }
        return dp[0][n-1][1];
    }
};

