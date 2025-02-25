class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<n;i++) {                          //����nums
            if(dq.empty())                              //�ӿ�ʱ���±�i����β
                dq.push_back(i);
            else {                                          //�Ӳ���ʱ
                while(!dq.empty() && nums[dq.back()]<nums[i])
                    dq.pop_back();              //����βС��nums[i]��Ԫ�شӶ�β����
                dq.push_back(i);                    //��Ԫ���±�i����β
            }
            if(dq.front()<i-k+1)                //����ͷ���ڵ�Ԫ�شӶ�ͷ����
                dq.pop_front();
            if(i>=k-1)
                ans.push_back(nums[dq.front()]);    //�¶�ͷԪ����ӵ�ans��
        }
        return ans;
    }
};

