class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hmap;
        int m=nums1.size();
        int n=nums2.size();
        stack<int> st;              //小顶栈
        for (int i=0;i<n;i++) {
            while (!st.empty() && st.top()<nums2[i]) {
                hmap[st.top()]=nums2[i];
                st.pop();           //将小于nums[i]的元素出栈
            }
            st.push(nums2[i]);
        }
        vector<int> ans(m,-1);					//初始化所有元素为-1
        for (int i=0;i<m;i++) {
            if (hmap.find(nums1[i])==hmap.end())
                continue;
            ans[i]=hmap[nums1[i]];
        }
        return ans;
    }
};

