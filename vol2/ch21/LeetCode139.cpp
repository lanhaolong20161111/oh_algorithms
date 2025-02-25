class Solution {
public:
    bool wordBreak(string s,vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> hset;						//�����ϣ����
        for (auto e:wordDict) hset.insert(e);
        vector<bool> dp=vector<bool>(n+1,false);		//һά��̬�滮����
        dp[0]=true;
        for(int i=1;i<=n;i++) {
            for (int j=0;j<i;j++) {
                string w=s.substr(j,i-j);   					//w=s[j..i-1]
                if (dp[j] && hset.count(w)>0) {
                    dp[i]=true;
                    break;											//ֻ�����dp[i]Ϊtrue�˳�for j��ѭ��
                }
            }
        }
        return dp[n];
    }
};

