class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> revadj(n);//��ͼ�ڽӱ�
        vector<int> degree(n,0);               //��ŷ�ͼ�����
        vector<int> ans;
        queue<int> qu;                      //�Է�ͼ������������
        for(int i=0;i<n;i++) {
            degree[i]=graph[i].size();
            if(degree[i]==0) qu.push(i);      //���Ϊ0�Ķ������
            for(int j:graph[i])
                revadj[j].push_back(i);
        }
        while(!qu.empty()) {                //�ֲ�εĲ�α���
            int cnt=qu.size();
            for(int i=0;i<cnt;i++) {
                int u=qu.front();qu.pop();
                ans.push_back(u);
                for(int v:revadj[u]) {
                    degree[v]-=1;
                    if(degree[v]==0) qu.push(v);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

