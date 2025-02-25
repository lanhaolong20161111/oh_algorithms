class Solution {
public:
    bool wordBreak(string s,vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> hset;						//定义哈希集合
        for (auto e:wordDict) hset.insert(e);
        vector<bool> dp=vector<bool>(n+1,false);		//一维动态规划数组
        dp[0]=true;
        for(int i=1;i<=n;i++) {
            for (int j=0;j<i;j++) {
                string w=s.substr(j,i-j);   					//w=s[j..i-1]
                if (dp[j] && hset.count(w)>0) {
                    dp[i]=true;
                    break;											//只有求出dp[i]为true退出for j的循环
                }
            }
        }
        return dp[n];
    }
};

