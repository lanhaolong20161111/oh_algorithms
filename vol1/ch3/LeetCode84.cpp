class Solution {
public:
    int largestRectangleArea(vector<int>&a) {
        a.insert(a.begin(),0);
        a.push_back(0);
        int n=a.size();
        stack<int> st;
        int ans=0;                                  //����������������ʼΪ0
        for (int j=0;j<n;j++) {                     //����a
            while(!st.empty() && a[st.top()]>a[j]) {
                int k=st.top(); st.pop();           //��ջk
                int length=j-st.top()-1;
                int area=a[k]*length;  
                ans=max(ans,area);
            }
            st.push(j);                             //j��ջ
        }
        return ans;
    }
};

