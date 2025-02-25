bool cmp(const vector<int>&e1,const vector<int>&e2) {
    if(e1[0]==e2[0])            //�����ͬʱ���߶ȵ�������
        return e1[1]>e2[1];
    else                        //���򰴸߶ȵݼ�����
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
    int lengthOfLIS(vector<int>& nums) {		//������������еĳ���
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

