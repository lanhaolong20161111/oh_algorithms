class Solution {
    const int INF=0x3f3f3f3f;
    int ans=INF;
    vector<int> jobs;
    int k;
    vector<int> times;
public:
    int minimumTimeRequired(vector<int>& jobs,int k) {
  sort(jobs.begin(),jobs.end(),greater<int>());   //排序后，大的先试，如果不行，失败得更快
        this->jobs=jobs;
        this->k=k;
        times=vector<int>(k,0);
        dfs(0,0);
        return ans;
    }
    void dfs(int ct,int i) {    //回溯算法
        if(i==jobs.size())
            ans=ct;
        else {
            bool flag=true;				//前面没有空闲工人时为true
            for(int j=0;j<k;j++) {
                if(times[j]==0) {
                    if(!flag) return;       //剪支1：前面有空闲工人时跳过
                    flag=false;				//前面有空闲工人时置为false
                }
                times[j]+=jobs[i];          //工作i分配给工人j
                int curtime=max(ct,times[j]);   //剪支2
                if(curtime<=ans)
                    dfs(curtime,i+1);
                times[j]-=jobs[i];              //回溯
            }
        }
    }
};

