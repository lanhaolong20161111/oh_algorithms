class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;								//小顶栈
        for (int i=0;i<2*n-1;i++) {
            while (!st.empty() && nums[st.top()]<nums[i%n]) {
                ans[st.top()]=nums[i%n];		//栈顶元素的下一个更大元素为nums[i%n]
                st.pop();
            }
            st.push(i%n);
        }
        return ans;
    }
};

