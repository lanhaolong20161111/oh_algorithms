class Solution {
public:
	bool isMatch(string &s,string &p) {
     	int m=s.size(),n=p.size();
        	auto dp=vector<vector<bool>>(m+1,vector<bool>(n+1,false));
        	dp[0][0]=true;
        	for(int j=1;j<=n;j++) { 
          	if(p[j-1]=='*' && j-2>=0 && dp[0][j-2]) 
              	dp[0][j]=true;
        	}
        	for (int i=1;i<=m;i++) {
            	for (int j=1;j<=n;j++) {
                	if(p[j-1]!='*') {
                    	if (p[j-1]=='.'  || s[i-1]==p[j-1])
                        	dp[i][j]=dp[i-1][j-1];
                	}
				else {										// p[j-1]=='*'
                   	dp[i][j]=dp[i][j-2];
                    	if (p[j-2]=='.'  || s[i-1]==p[j-2])
                        	dp[i][j]=dp[i][j] || dp[i-1][j];
                	}
            	}
        	}
        	return dp[m][n];
    	}
};

