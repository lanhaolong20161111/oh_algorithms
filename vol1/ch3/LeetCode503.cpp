class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;								//С��ջ
        for (int i=0;i<2*n-1;i++) {
            while (!st.empty() && nums[st.top()]<nums[i%n]) {
                ans[st.top()]=nums[i%n];		//ջ��Ԫ�ص���һ������Ԫ��Ϊnums[i%n]
                st.pop();
            }
            st.push(i%n);
        }
        return ans;
    }
};

