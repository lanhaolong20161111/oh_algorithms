struct Cmp {
    bool operator()(const int&a,const int&b) const {
        return a>b;         //ָ����Ԫ��ֵ�ݼ�����
    }
};
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int,Cmp> tset;
        for(int x:nums)
            tset.insert(x);
        auto it=tset.begin();
        if(tset.size()>=3) {
            it++; it++;
        }
        return *it;
    }
};

