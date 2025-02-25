class Solution {
public:
    int largestRectangleArea(vector<int>&a) {
        a.insert(a.begin(),0);
        a.push_back(0);
        int n=a.size();
        stack<int> st;
        int ans=0;                                  //存放最大矩形面积，初始为0
        for (int j=0;j<n;j++) {                     //遍历a
            while(!st.empty() && a[st.top()]>a[j]) {
                int k=st.top(); st.pop();           //退栈k
                int length=j-st.top()-1;
                int area=a[k]*length;  
                ans=max(ans,area);
            }
            st.push(j);                             //j进栈
        }
        return ans;
    }
};

