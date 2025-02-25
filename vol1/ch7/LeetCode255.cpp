class Solution {
public:
    bool verifyPreorder(vector<int>& pres) {
        int n=pres.size();
        stack<int> st;									//单调递减栈
        int rootd=-1;                						//初始化为最小元素值
        for (int i=0;i<n;i++) {
            if (pres[i]<rootd) return false;
            while (!st.empty() && pres[i]>st.top()) {
                rootd=st.top(); 							//记录子树的根结点值
				st.pop();									//将小于pres[i]的栈顶元素出栈
            }
            st.push(pres[i]);							//pres[i]进栈
        }
        return true;
    }
};

