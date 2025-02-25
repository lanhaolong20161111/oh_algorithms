class Solution {
public:
    vector<int> getModifiedArray(int n,vector<vector<int>>&updates) {
        vector<int> diff(n,0);
        int low,high,c;
        for (int i=0;i<updates.size();i++) {
            low=updates[i][0];
            high=updates[i][1];
            c=updates[i][2];
            Update(diff,low,high,c);
        }
        return geta(diff);
    }
    void Update(vector<int>&diff,int low,int high,int c) {  //通过diff将A[low..high]增加c
        diff[low]+=c;
        if(high+1<diff.size())
            diff[high+1]-=c;
    }
    vector<int> geta(vector<int>&diff) {        //由差分数组diff构造ans
        int n=diff.size();
        vector<int> ans(n);
        ans[0]=diff[0];
        for(int i=1;i<n;i++)
            ans[i]=ans[i-1]+diff[i];
        return ans;
    }
};

