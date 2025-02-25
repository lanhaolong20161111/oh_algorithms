typedef pair<int,int> PII;
struct HashFunc {
    size_t operator()(const PII&p) const {
        return std::hash<int>()(p.first)^std::hash<int>()(p.second);
    }
};
struct EqualKey {
    bool operator ()(const PII&p1,const PII&p2) const {
        return p1.first==p2.first && p1.second==p2.second;
    }
};
class Solution {
public:
    bool canMeasureWater(int C1,int C2,int T) {
        queue<PII> qu;                      //����һ������
        qu.emplace(0,0);
        unordered_set<pair<int,int>,HashFunc,EqualKey> hset;    //�ù�ϣ�����ж�״̬�ظ�
        hset.insert(PII(0,0));
        while (!qu.empty()) {
            auto [cap1,cap2]=qu.front();qu.pop();
            if (cap1==T || cap2==T || cap1+cap2==T)
                return true;
            if(hset.count(PII(C1,cap2))==0) {      //����1װ��
                hset.insert(PII(C1,cap2));
                qu.emplace(C1,cap2);
            }
            if(hset.count(PII(cap1,C2))==0) {      //����2װ��
                hset.insert(PII(cap1,C2));
                qu.emplace(cap1,C2);
            }
             if(hset.count(PII(0,cap2))==0) {      //����1���
                hset.insert(PII(0,cap2));
                qu.emplace(0,cap2);
             }
             if(hset.count(PII(cap1,0))==0) {      //����2���
                hset.insert(PII(cap1,0));
                qu.emplace(cap1,0);
             }
            int need=min(cap1,C2-cap2);                  //ȡ��1�ͺ�2ʣ��ռ����Сֵ
            if(hset.count(PII(cap1-need,cap2+need))==0) {
                hset.insert(PII(cap1-need,cap2+need));  //����1�е�needˮ�����2
                qu.emplace(cap1-need,cap2+need);
            }
            need=min(cap2,C1-cap1);                  //ȡ��2�ͺ�1ʣ��ռ����Сֵ
            if(hset.count(PII(cap1+need,cap2-need))==0) {
                hset.insert(PII(cap1+need,cap2-need));  //����2�е�needˮ�����1
                qu.emplace(cap1+need,cap2-need);
            }
        }
        return false;
    }
};

