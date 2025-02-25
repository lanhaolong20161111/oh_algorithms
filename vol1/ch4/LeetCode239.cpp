class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<n;i++) {                          //遍历nums
            if(dq.empty())                              //队空时将下标i进队尾
                dq.push_back(i);
            else {                                          //队不空时
                while(!dq.empty() && nums[dq.back()]<nums[i])
                    dq.pop_back();              //将队尾小于nums[i]的元素从队尾出队
                dq.push_back(i);                    //将元素下标i进队尾
            }
            if(dq.front()<i-k+1)                //将队头过期的元素从队头出队
                dq.pop_front();
            if(i>=k-1)
                ans.push_back(nums[dq.front()]);    //新队头元素添加到ans中
        }
        return ans;
    }
};

