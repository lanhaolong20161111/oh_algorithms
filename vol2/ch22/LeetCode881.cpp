class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());		//��������
        int i=0,j=people.size()-1;
        int ans=0;
        while(i<=j) {
            if(i==j) {      //���������ʣ�����һ���˵���
                ans++;
                break;
            }
            if(people[i]+people[j]<=limit) {    //ǰ��������ͬ��
                ans++;
                i++; j--;
            }
            else {                              //��j���˵���
                ans++;
                j--;
            }
        }
        return ans;
    }
};

