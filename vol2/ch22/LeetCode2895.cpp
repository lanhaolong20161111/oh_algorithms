class Solution {
public:
    int minProcessingTime(vector<int>& processorTime,vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());    //µ›‘ˆ≈≈–Ú
        sort(tasks.begin(),tasks.end(),greater<int>());     //µ›ºı≈≈–Ú
        int ans=0;
        for(int i=0;i<processorTime.size();i++)
            ans=max(ans,tasks[4*i]+processorTime[i]);
        return ans;
    }
};

