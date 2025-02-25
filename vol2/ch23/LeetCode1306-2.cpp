class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        if(arr[start]==0) return true;
        vector<bool> visited(n,false);
        queue<int> qu;
        qu.push(start);
        visited[start]=true;
        while (!qu.empty()) {
            int i=qu.front();qu.pop();					//出队位置i
            int p1=i+arr[i];
            if (p1<n && !visited[p1]) {
                if (arr[p1]==0) return true;			//找到为0的位置返回true
                qu.push(p1);
                visited[p1]=true;
            }
            int p2=i-arr[i];
            if (p2>=0 && !visited[p2]) {
                if (arr[p2]==0) return true;			//找到为0的位置返回true
                qu.push(p2);
                visited[p2]=true;
            }
        }
        return false;
    }
};

