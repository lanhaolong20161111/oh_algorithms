class Solution {
    vector<bool> visited;
public:
    bool canReach(vector<int>& arr,int start) {
        int n=arr.size();
        visited=vector<bool>(n,false);
        return dfs(arr,start);
    }
    bool dfs(vector<int>& arr,int i) {
        if (i<0 || i>=arr.size())
            return false;
        if(visited[i]) return false;
        if(arr[i]==0) return true;
        visited[i]=true;
        if(dfs(arr,i+arr[i])) return true;
        if(dfs(arr,i-arr[i])) return true;
        return false;
    }
};

