class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        stack<int> st;
        for (int i=0;i<n;i++) {
            while(!st.empty() && temperatures[st.top()]<temperatures[i]) {
                int prei=st.top();
                ans[prei]=i-prei;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

