class Solution {
public:
    bool canReach(string s,int minJump,int maxJump) {
        int n=s.size();
		if(s[n-1]=='1') return false;
        vector<int> dp(n,0);
        vector<int> presum(n+1,0);
        presum[0]=0;
        presum[1]=1;
        dp[0]=1;
        for(int i=1;i<n;i++){
            if(s[i]=='0') {
                int l=max(0,i-maxJump),r=i-minJump;
                if(r>=0 && l<=r && presum[r+1]-presum[l]>0)
                    dp[i]=1;
            }
            presum[i+1]=presum[i]+dp[i];
        }
        return dp[n-1];
    }
};

