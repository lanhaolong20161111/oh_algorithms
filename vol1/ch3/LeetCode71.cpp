class Solution {
public:
 	string simplifyPath(string path) {
      	int n=path.size();
       	stringstream ss;
       	ss << path;
       	string word;
       	stack<string> st;
       	while (getline(ss, word, '/')) {          	//ȡpath����'/'�ָ����ַ���word
         	if (word==".")                         		//����"."
               	continue;
           	else if (word=="..") {                  	//����".."�����һ��
                	if (!st.empty()) st.pop();
            	}
            	else if (!word.empty())             		//���������ǿ�word�������ջ
                	st.push(word);
        	}
        	if (st.empty()) return "/";					//�������
        	string ans="";
       		while(!st.empty()) {							//��st��Ԫ�ؼ�'/'����������
            	ans="/"+st.top()+ans;
            	st.pop();
        	}
        	return ans;
    	}
};

