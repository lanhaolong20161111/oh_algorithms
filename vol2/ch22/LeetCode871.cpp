class Solution {
public:
   int minRefuelStops(int target,int startFuel,vector<vector<int>>&stations) {
        int n=stations.size();
        priority_queue<int> pqu;                //�����
        int ans=0;
        int fuel=startFuel;                         //��ǰ����
        int i=0;
        while(i<n) {
            if(fuel>=stations[i][0]) {              //�ܹ��������վi
                pqu.push(stations[i][1]);       //����ǰ����վ���������
                i++;                            //������ʻ
            }
            else {                                  //���ܹ��������վi
                if (!pqu.empty()) {
                    fuel+=pqu.top(); pqu.pop();     //ѡ���������ļ���
                    ans++;
                }                                   //û������ʱ����-1
                else return -1;
            }
        }
        while(!pqu.empty() && fuel<target) {    //û�е���Ŀ�ĵ�ʱ
            fuel+=pqu.top(); pqu.pop();
            ans++;
        }
        if(fuel>=target) return ans;
        return -1;
    }
};

