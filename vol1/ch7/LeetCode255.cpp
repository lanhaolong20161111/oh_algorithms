class Solution {
public:
    bool verifyPreorder(vector<int>& pres) {
        int n=pres.size();
        stack<int> st;									//�����ݼ�ջ
        int rootd=-1;                						//��ʼ��Ϊ��СԪ��ֵ
        for (int i=0;i<n;i++) {
            if (pres[i]<rootd) return false;
            while (!st.empty() && pres[i]>st.top()) {
                rootd=st.top(); 							//��¼�����ĸ����ֵ
				st.pop();									//��С��pres[i]��ջ��Ԫ�س�ջ
            }
            st.push(pres[i]);							//pres[i]��ջ
        }
        return true;
    }
};

