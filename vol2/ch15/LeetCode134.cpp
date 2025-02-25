class Solution {
public:
    int canCompleteCircuit(vector<int>& gas,vector<int>& cost) {
        int n=gas.size();
        int diffsum=0;
        for (int i=0;i<n;i++)
           diffsum+=gas[i]-cost[i];
        if (diffsum<0) return -1;   //����վ����������С�����е�·��
        int curgas=0;               //��¼��ǰ��������
        int i=0;
        int ans=0;                  //��Ŵ�
        while (i<n) {               //����ÿ������վ
            curgas+=gas[i]-cost[i];     //�ڼ���վi����gas[i]
            if (curgas>=0) i++;         //����������Ǹ���
            else {
                curgas=0;           //�Ӽ���վi+1���¿�ʼ
                ans=i+1;
                i++;
            }
        }
        return ans;
    }
};

