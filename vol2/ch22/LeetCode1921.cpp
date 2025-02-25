class Solution {
public:
    int eliminateMaximum(vector<int>& dist,vector<int>& speed) {
        int n=dist.size();
        vector<int> times(n);
        for (int i=0;i<n;i++)
            times[i]=(dist[i]-1)/speed[i]+1;
       sort(times.begin(),times.end());
       int ans=0;					//�������Ĺ������
        for (int i=0;i<n;i++) {
            if(times[i]>i) ans++;
            else return ans;
        }
        return n;
    }
};

