class Solution {
    vector<vector<int>> adj;            //�ڽӱ�
    vector<vector<bool>> path;          //path[i][j]��ʾi��j�Ƿ���·��
    vector<int> degree;                 //��������
public:
    vector<bool> checkIfPrerequisite(int n,vector<vector<int>>&prereqs,vector<vector<int>>&ques) {
        adj=vector<vector<int>>(n);
        path=vector<vector<bool>>(n,vector<bool>(n,false));
        degree=vector<int>(n,0);
        for (int i=0;i<prereqs.size();i++) {    //���б����ڽӱ�
            int a=prereqs[i][0];                //[a,b]��ʾa��b�����޿γ�
            int b=prereqs[i][1];
            adj[a].push_back(b);                //��<a,b>��ʾ������a,����b
            degree[b]++;                        //b�������1
        }
        topsort(n);
        vector<bool> ans(ques.size()); 
        for (int i=0;i<ques.size();i++)
            ans[i]=path[ques[i][0]][ques[i][1]];
        return ans;
    }
    void topsort(int n) {                //��������
        stack<int> st;
        for(int i=0;i<n;i++) {         //���Ϊ0�Ŀγ̽�ջ
            if(degree[i]==0) st.push(i);
        }
        while(!st.empty()) {            //ջ����ѭ��
            int i=st.top();st.pop();    //��ջ�γ�i
            for (int j:adj[i]) {        //���ǿγ�i�ĳ��߿γ�j
                degree[j]--;             //�γ�k����ȼ�1
                path[i][j]=true;         //i��j�����޿γ�
                for(int k=0;k<n;k++) {   //i�����޿γ�kҲ��j�����޿γ�
                    if(path[k][i]) path[k][j]=true;
                }
                if (degree[j]==0) st.push(j);
            }
        }
    }
};

