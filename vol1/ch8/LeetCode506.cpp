struct Player {
    int i;															//�˶�Ա���
    int mark;													//�˶�Ա�ɼ�
    Player(int i,int m):i(i),mark(m) {}
    bool operator<(const Player&a) const {
        return mark>a.mark;									//ָ����mark�ݼ�����
    }
};
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        set<Player> tset;
        for(int i=0;i<n;i++)
            tset.insert(Player(i,score[i]));
        vector<string> ans(n);
        int i=1;
        for(auto c : tset) {
            if(i==1) ans[c.i]="Gold Medal";
            else if(i==2) ans[c.i]="Silver Medal";
            else if(i==3) ans[c.i]="Bronze Medal";
            else ans[c.i]=to_string(i);
            i++;
        }
        return ans;
    }
};

