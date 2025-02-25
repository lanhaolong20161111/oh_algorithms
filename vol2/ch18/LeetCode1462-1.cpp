class Solution {
    vector<vector<int>> adj;            		//�ڽӱ�
    vector<vector<bool>> path;          	//path[i][j]��ʾi��j�Ƿ���·��
public:
    vector<bool> checkIfPrerequisite(int n,vector<vector<int>>&prereqs,vector<vector<int>>&ques) {
        adj=vector<vector<int>>(n);
        path=vector<vector<bool>>(n,vector<bool>(n,false));
        for (int i=0;i<prereqs.size();i++) {    //���б����ڽӱ�
            int a=prereqs[i][0];                //[a,b]��ʾa��b�����޿γ�
            int b=prereqs[i][1];
            adj[a].push_back(b);                //��<a,b>��ʾ������a,����b
        }
        for (int i=0;i<n;i++)                   //��γ�i����Щ�γ���·��
            dfs(n,i,i);
        vector<bool> ans(ques.size()); 
        for (int i=0;i<ques.size();i++)
            ans[i]=path[ques[i][0]][ques[i][1]];
        return ans;
    }
    void dfs(int n,int i,int u) {       //�ӿγ�u������������ȱ���
        path[i][u]=true;                //��ʾ�γ�i��u��·��
        for(int v:adj[u]) {             //���ǿγ�u�ĳ��߿γ�v
            if(path[i][v]) continue;
            path[i][v]=true;            //��ʾ�γ�i��v��·��
            dfs(n,i,v);                 //�ӿγ�v��������
        }
    }
};

