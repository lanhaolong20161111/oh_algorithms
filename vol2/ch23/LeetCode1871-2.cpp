class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        if(s[n-1]=='1') return false;
        int presum[n+1];
        presum[0]=0;
        for(int i=1;i<=n;i++) {
            if(s[i-1]=='1') presum[i]=presum[i-1]+1;
            else presum[i]=presum[i-1];
        }
        priority_queue<int> pqu;
        pqu.push(0);                    //从位置0开始跳
        vector<bool> visited(n,false);
        visited[0]=true;
        while(!pqu.empty()) {
            int i=pqu.top();pqu.pop();
            if(i==n-1) return true;
            int l=i+minJump,r=i+maxJump;
            if(r<n && presum[r+1]-presum[i]==maxJump)
                return false;                           //剪支1
            if(r>=n-1 && presum[n]-presum[i]==n-i-1)
                return false;
            if(r<n && presum[r+1]-presum[l]==maxJump-minJump+1)
                continue;                               //剪支2
            for(int j=l;j<=r && j<n;j++) {
                if(!visited[j] && s[j]=='0') {
                    if(j==n-1) return true;
                    visited[j]=true;    //防止重复访问
                    pqu.push(j);
                }
            }
        }
        return false;
    }
};

