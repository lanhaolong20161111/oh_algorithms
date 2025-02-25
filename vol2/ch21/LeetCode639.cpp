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
            if(s[i-1]!='*') {									//���(1)
                if(s[i-1]!='0')								//�������
                    dp[i]=dp[i-1];
                if(s[i-2]=='1')								//�������
                    dp[i]+=dp[i-2];
                else if(s[i-2]=='2' && s[i-1]<'7')		//�������
                    dp[i]+=dp[i-2];
                else if(s[i-2]=='*') {							//�������
                    if (s[i-1]<'7')
                        dp[i]+=(dp[i-2]*2);
                    else
                        dp[i]+=dp[i-2];
                }
            }
            else {											//���(2)
                dp[i]=dp[i-1]*9;						//�������
                if(s[i-2]=='1')							//�������
                    dp[i]+=dp[i-2]*9;
                else if(s[i-2]=='2')					//�������
                    dp[i]+=dp[i-2]*6;
                else if(s[i-2]=='*')					//�������
                    dp[i]+=dp[i-2]*15;
            }
            dp[i] %= mod;
        }
        return dp[n];
    }
};

