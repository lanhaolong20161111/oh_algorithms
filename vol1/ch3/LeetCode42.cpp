class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        int ans=0;
        stack<int> st;              //µ¥µ÷Ð¡¶¥Õ»
        for(int i=0;i<n;i++) {
            while(!st.empty() && a[st.top()]<a[i]) {
                int k=st.top(); st.pop();
                if (!st.empty()) {
                    int l=st.top();
                    int r=i;
                    int h=min(a[r],a[l])-a[k];
                    ans+=(r-l-1)*h;
                }
            }
            st.push(i);
        }
        return ans;
    }
};

