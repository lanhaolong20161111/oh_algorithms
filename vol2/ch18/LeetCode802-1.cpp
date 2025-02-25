class Solution {
    vector<bool> visited;
    vector<bool> safe;
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> ans;
        safe=vector<bool>(n,false);             //��ʼ��safe
        for(int i=0;i<n;i++) {                  //��̽ÿ������i
            visited=vector<bool>(n,false);      //��ʼ��visited
            if(dfs(graph,i)) ans.push_back(i);
        }
        return ans;
    }
    bool dfs(vector<vector<int>>&graph,int i) {    //��i����DFS�Ƿ��ҵ��յ�
        if(safe[i]) return true;                    //i�ǰ�ȫ�ģ�����true
        if(visited[i]) return false;                //i���ʹ�������false
        if(graph[i].empty()) {                      //�����յ�i��û�г��ߣ�
            safe[i]=true;                           //i�ǰ�ȫ��
            return true;                            //����true
        }
        visited[i]=true;
        for(int j:graph[i]) {                       //����i��ÿ�����ڵ�j
            if (!dfs(graph,j))                      //����һ�߲����㷵�ؼ�
                return false;
        }
        safe[i]=true;                               //i�ǰ�ȫ��
        return true;                                //����true
    }
};

