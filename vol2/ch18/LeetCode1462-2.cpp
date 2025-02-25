class Solution {
    vector<vector<int>> adj;            //�ڽӱ�
    vector<vector<bool>> path;                  //path[i][j]��ʾi��j�Ƿ���·��
public:
    vector<bool> checkIfPrerequisite(int n,vector<vector<int>>&prereqs,vector<vector<int>>&ques) {
        adj=vector<vector<int>>(n);
        path=vector<vector<bool>>(n,vector<bool>(n,false));
        for (int i=0;i<prereqs.size();i++) {    //���б����ڽӱ�
            int a=prereqs[i][0];                //[a,b]��ʾa��b�����޿γ�
            int b=prereqs[i][1];
            adj[a].push_back(b);                //��<a,b>��ʾ������a,����b
        }
        for(int i=0;i<n;i++)
            bfs(n,i);
        vector<bool> ans(ques.size()); 
        for (int i=0;i<ques.size();i++)
            ans[i]=path[ques[i][0]][ques[i][1]];
        return ans;
    }
    void bfs(int n,int i) {                                   //������ȱ����㷨
        queue<int> qu;                              //����һ������qu
        path[i][i]=true;                            //�Լ����Լ���·��
        qu.push(i);                                 //�γ�i����
        while (!qu.empty()) {                       //�Ӳ���ѭ��
            int cnt=qu.size();
            for(int j=0;j<cnt;j++) {
                int u=qu.front(); qu.pop();         //���ӿγ�u
                for(int v:adj[u]) {                 //���ǿγ�u�ĳ��߿γ�v
                    if(path[i][v]) continue;
                    path[i][v]=true;                //��ʾ�γ�i��v��·��
                    qu.push(v);                     //�γ�v����
                }
            }
        }
    }
};

