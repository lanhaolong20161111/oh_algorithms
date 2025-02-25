typedef unsigned long long ULL;
class Solution {
public:
    const static ULL mod=1000000007;    
    int numDecodings(string s) {
        int n=s.size();
        vector<ULL> dp=vector<ULL>(n+1,0);
        dp[0]=1;
        dp[1]=(s[0]=='*'? 9:1);
        if(s[0]=='0') dp[0]=dp[1]=0;
        for(int i=2;i<=n;i++) {
            if(s[i-1]!='*') {									//情况(1)
                if(s[i-1]!='0')								//子情况①
                    dp[i]=dp[i-1];
                if(s[i-2]=='1')								//子情况②
                    dp[i]+=dp[i-2];
                else if(s[i-2]=='2' && s[i-1]<'7')		//子情况③
                    dp[i]+=dp[i-2];
                else if(s[i-2]=='*') {							//子情况④
                    if (s[i-1]<'7')
                        dp[i]+=(dp[i-2]*2);
                    else
                        dp[i]+=dp[i-2];
                }
            }
            else {											//情况(2)
                dp[i]=dp[i-1]*9;						//子情况①
                if(s[i-2]=='1')							//子情况②
                    dp[i]+=dp[i-2]*9;
                else if(s[i-2]=='2')					//子情况③
                    dp[i]+=dp[i-2]*6;
                else if(s[i-2]=='*')					//子情况④
                    dp[i]+=dp[i-2]*15;
            }
            dp[i] %= mod;
        }
        return dp[n];
    }
};

