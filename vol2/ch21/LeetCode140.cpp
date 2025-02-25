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
                    dp[i].push_back(j);				//将所有这样的j添加到dp[i]中
            }
        }
        if(dp[n].empty()) return {};					//不能被拆分时
        vector<string> path;								//一个解
        dfs(s,path,dp,n);
        return ans;
    }
    void dfs(string&s,vector<string>&path,vector<vector<int>>&dp,int i) {
        if(i==0) {										//i对应前缀s[0..i-1]的长度，为0时对应叶子结点
            string tmp=path.back();     		//由path反向串起来构成一个解tmp
            for(int k=path.size()-2;k>=0;k--) {
                tmp+=" ";
                tmp+=path[k];
            }   
            ans.push_back(tmp);
        }
        else {
            for(auto j:dp[i]) {							//考虑所有可能的最后单词
					string w=s.substr(j,i-j);   			//说明s[j..i-1]是单词
                path.push_back(w);
                dfs(s,path,dp,j);						//转向子问题
                path.pop_back();					//回溯
            }
        }
    }
};

