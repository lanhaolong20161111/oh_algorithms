class Solution {
public:
	string removeDuplicateLetters(string s) {
     	vector<int> cnt(26,0);						//计数数组
        	vector<int> visited(26,0);					//判定字母是否在栈中
        	for (auto c:s) cnt[c-'a']++;			//累计每个字母出现的次数
        	stack<char> st;
        	for (auto c:s) {
            	if (visited[c-'a']) {					//c在栈中的情况
                	cnt[c-'a']--;
            	}
			else {										//c不在栈中的情况
            		while (!st.empty() && st.top()>c && cnt[st.top()-'a']>=1) {
                		visited[st.top()-'a']=0;		//出栈递减且后面还有的字母
                		st.pop();
            		}
            		st.push(c);
            		cnt[c-'a']--;
            		visited[c-'a']=1;
        		}
		}
        	int n=st.size();
        	string ans(n,'a');
        	for (int i=n-1;i>=0;i--) {
            	ans[i]=st.top();
            	st.pop();
        	}
        	return ans;
    	}
};

