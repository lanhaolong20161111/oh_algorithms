bool cmp(const vector<int>&e1,const vector<int>&e2) {
    if(e1[0]==e2[0])            //宽度相同时按高度递增排序
        return e1[1]>e2[1];
    else                        //否则按高度递减排序
        return e1[0]<e2[0];
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        if (n==1) return 1;
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> height;
        for(int i=0;i<n;i++)
            height.push_back(envelopes[i][1]);
        return lengthOfLIS(height);
    }
    int lengthOfLIS(vector<int>& nums) {		//求最长递增子序列的长度
        int n=nums.size();
        vector<int> ans={nums[0]};
        for (int i=1;i<n;i++) {
            int curd=nums[i];
            if (curd>ans.back())        //大于ans中最大数时直接添加
                ans.push_back(curd);
            else {
                auto it=lower_bound(ans.begin(),ans.end(),curd);
                *it=curd;               //替换
            }
        }
        return ans.size();
    }
};

