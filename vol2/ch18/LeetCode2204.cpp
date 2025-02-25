class Solution {
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> path;
public:
    vector<int> distanceToCycle(int n,vector<vector<int>>& edges) {
        adj=vector<vector<int>>(n);
        for(auto e:edges) {						//�����ڽӱ�adj
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> cycle=findCycle(n);			//�ҵ���cycle
        vector<int> ans(n,n+1);
        for(int i:cycle) ans[i]=0;
        queue<int> qu;
        for(int i:cycle) qu.push(i);  				//����cycle��ȫ���������
        int dist=0;
        while(!qu.empty()) {        				//�����ǲ�εĹ����������
            int cnt=qu.size();
            for(int i=0;i<cnt;i++) {
                int cur=qu.front(); qu.pop();
                for(int next:adj[cur]) {
                    if(ans[next]>dist+1) {
                        ans[next]=dist+1;
                        qu.push(next);
                    }
                }
            }
            dist+=1;
        }
        return ans;
    }
    bool dfs(int u,int pre) {   //����⣬����¼Ψһ�Ļ�cycle
        if(visited[u]) return true;
        visited[u]=true;
        for(int v:adj[u]) {       					//����(u,v)��
            if(v==pre) continue;      			//����(u,v,u)�Ļ�
            path.push_back(v);					//��v��ӵ�path��
            if(dfs(v,u)) return true;				//�ҵ��󷵻�true
            path.pop_back();         			//����
        }
        return false;
    }
    vector<int> findCycle(int n) {
        vector<int> cycle;                    //��Ż��ϵĶ���
        path={};
        visited=vector<bool>(n,false);
        for(int i=0;i<n;i++) {
            if(visited[i]) continue;
            path.push_back(i);
            if(dfs(i,-1)) break;
        }
        int last=path.back();
        path.pop_back();
        cycle.push_back(last);
        while(!path.empty() &&  path.back()!=last) {
            cycle.push_back(path.back());
            path.pop_back();
        }
        return cycle;
    }
};

