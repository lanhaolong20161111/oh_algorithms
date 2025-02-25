class Solution {
    const int INF=0x3f3f3f3f;
    int ans=INF;
    vector<int> jobs;
    int k;
    vector<int> times;
public:
    int minimumTimeRequired(vector<int>& jobs,int k) {
  sort(jobs.begin(),jobs.end(),greater<int>());   //����󣬴�����ԣ�������У�ʧ�ܵø���
        this->jobs=jobs;
        this->k=k;
        times=vector<int>(k,0);
        dfs(0,0);
        return ans;
    }
    void dfs(int ct,int i) {    //�����㷨
        if(i==jobs.size())
            ans=ct;
        else {
            bool flag=true;				//ǰ��û�п��й���ʱΪtrue
            for(int j=0;j<k;j++) {
                if(times[j]==0) {
                    if(!flag) return;       //��֧1��ǰ���п��й���ʱ����
                    flag=false;				//ǰ���п��й���ʱ��Ϊfalse
                }
                times[j]+=jobs[i];          //����i���������j
                int curtime=max(ct,times[j]);   //��֧2
                if(curtime<=ans)
                    dfs(curtime,i+1);
                times[j]-=jobs[i];              //����
            }
        }
    }
};

