class Solution {
public:
    vector<string> buildArray(vector<int>& target,int n) {
        vector<string> ans;
        int j=0;                            //����target����
        for(int i=1;i<=n;i++) {
            ans.push_back("Push");          //i��ջ
            if (i!=target[j])               //target����ĵ�ǰԪ�ز�����i
                ans.push_back("Pop");       //��ջi
            else                            //target����ĵ�ǰԪ�ص���i
                j++;
            if (j==target.size())           //target���������ʱ�˳�ѭ��
                break;
        }
        return ans;        
    }
};

