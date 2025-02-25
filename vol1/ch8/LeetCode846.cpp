class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n=hand.size();
        if(n%k!=0) return false;
        map<int,int> tmap;
        for(int i=0;i<n;i++) tmap[hand[i]]++;
        while(!tmap.empty()) {
            auto it=tmap.begin();      //����tmap
            int x=it->first;
            for(int i=0;i<k;i++) {      //��������k������
                if(it->first!=x+i)      //û���ҵ�����false
                    return false;
                it->second--;           //��itָ�����ָ�����1
                if(it->second==0)       //���ָ���Ϊ0ʱ��tmap��ɾ����Ԫ��
                    tmap.erase(it);
                it++;
            }
        }
        return true;
    }
};

