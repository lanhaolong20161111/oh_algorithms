class Solution {
public:
	string removeDuplicateLetters(string s) {
     	vector<int> cnt(26,0);						//��������
        	vector<int> visited(26,0);					//�ж���ĸ�Ƿ���ջ��
        	for (auto c:s) cnt[c-'a']++;			//�ۼ�ÿ����ĸ���ֵĴ���
        	stack<char> st;
        	for (auto c:s) {
            	if (visited[c-'a']) {					//c��ջ�е����
                	cnt[c-'a']--;
            	}
			else {										//c����ջ�е����
            		while (!st.empty() && st.top()>c && cnt[st.top()-'a']>=1) {
                		visited[st.top()-'a']=0;		//��ջ�ݼ��Һ��滹�е���ĸ
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

