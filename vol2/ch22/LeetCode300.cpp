class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans={nums[0]};
        for (int i=1;i<n;i++) {
            int curd=nums[i];
            if (curd>ans.back())        //����ans�������ʱֱ�����
                ans.push_back(curd);
            else {
                auto it=lower_bound(ans.begin(),ans.end(),curd);
                *it=curd;               //�滻
            }
        }
        return ans.size();
    }
};

