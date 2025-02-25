class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        int n=expression.size();
        if(n==1||n==2){
            ans.push_back(stoi(expression));
            return ans;
        }
        for(int i=0;i<n;i++){
            int c=expression[i];
            if(c=='+'||c=='-'||c=='*'){
               vector<int> lefts=diffWaysToCompute(expression.substr(0,i));
                vector<int> rights=diffWaysToCompute(expression.substr(i+1));
                for(auto l:lefts){				//����Ͻ��ͨ����������
                    for(auto r:rights) {
                        switch(c){
                            case '+': ans.push_back(l+r); break;
                            case '-': ans.push_back(l-r); break;
                            case '*': ans.push_back(l*r); break;
                        }
                    }
                }
            }
        }
        return ans;          //���غϲ���Ľ��
    }
};

