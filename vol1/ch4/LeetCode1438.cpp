class Solution {
public:
    int longestSubarray(vector<int>& nums,int limit) {
        deque<int> maxdq, mindq;
        int ans=0,n=nums.size();
        int low=0,high=0;           //´°¿ÚµÄ×óÓÒ±ß¿ò
        while (high<n) {
            while (!maxdq.empty() && maxdq.back()<nums[high])
                maxdq.pop_back();
            while (!mindq.empty() && mindq.back()>nums[high])
                mindq.pop_back();
            mindq.push_back(nums[high]);
            maxdq.push_back(nums[high]);
            while (maxdq.front()-mindq.front()>limit) {
                if (maxdq.front()==nums[low])
                    maxdq.pop_front();
                if (mindq.front()==nums[low])
                    mindq.pop_front();
                low++;
            }
             ans=max(ans,high-low+1);
             high++;
        }
        return ans;
    }
};

