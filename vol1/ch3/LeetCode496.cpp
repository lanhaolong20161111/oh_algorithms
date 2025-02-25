class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hmap;
        int m=nums1.size();
        int n=nums2.size();
        stack<int> st;              //С��ջ
        for (int i=0;i<n;i++) {
            while (!st.empty() && st.top()<nums2[i]) {
                hmap[st.top()]=nums2[i];
                st.pop();           //��С��nums[i]��Ԫ�س�ջ
            }
            st.push(nums2[i]);
        }
        vector<int> ans(m,-1);					//��ʼ������Ԫ��Ϊ-1
        for (int i=0;i<m;i++) {
            if (hmap.find(nums1[i])==hmap.end())
                continue;
            ans[i]=hmap[nums1[i]];
        }
        return ans;
    }
};

