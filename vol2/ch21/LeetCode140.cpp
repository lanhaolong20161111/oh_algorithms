class Solution {
    vector<string> ans;
public:
    string str;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet={wordDict.begin(), wordDict.end()};
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(0));
        dp[0]={0};
        for(int i=1;i<=n;i++) {
            for(int j=0;j<i;j++) {
                string w=s.substr(j,i-j);       		//w=s[i..j-1]
                if(dp[j].size() && wordSet.count(w))
                    dp[i].push_back(j);				//������������j��ӵ�dp[i]��
            }
        }
        if(dp[n].empty()) return {};					//���ܱ����ʱ
        vector<string> path;								//һ����
        dfs(s,path,dp,n);
        return ans;
    }
    void dfs(string&s,vector<string>&path,vector<vector<int>>&dp,int i) {
        if(i==0) {										//i��Ӧǰ׺s[0..i-1]�ĳ��ȣ�Ϊ0ʱ��ӦҶ�ӽ��
            string tmp=path.back();     		//��path������������һ����tmp
            for(int k=path.size()-2;k>=0;k--) {
                tmp+=" ";
                tmp+=path[k];
            }   
            ans.push_back(tmp);
        }
        else {
            for(auto j:dp[i]) {							//�������п��ܵ���󵥴�
					string w=s.substr(j,i-j);   			//˵��s[j..i-1]�ǵ���
                path.push_back(w);
                dfs(s,path,dp,j);						//ת��������
                path.pop_back();					//����
            }
        }
    }
};

