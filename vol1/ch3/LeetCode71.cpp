class Solution {
public:
 	string simplifyPath(string path) {
      	int n=path.size();
       	stringstream ss;
       	ss << path;
       	string word;
       	stack<string> st;
       	while (getline(ss, word, '/')) {          	//取path中由'/'分隔的字符串word
         	if (word==".")                         		//跳过"."
               	continue;
           	else if (word=="..") {                  	//遇到".."则回退一次
                	if (!st.empty()) st.pop();
            	}
            	else if (!word.empty())             		//遇到其他非空word，将其进栈
                	st.push(word);
        	}
        	if (st.empty()) return "/";					//特殊情况
        	string ans="";
       		while(!st.empty()) {							//将st中元素加'/'并连接起来
            	ans="/"+st.top()+ans;
            	st.pop();
        	}
        	return ans;
    	}
};

