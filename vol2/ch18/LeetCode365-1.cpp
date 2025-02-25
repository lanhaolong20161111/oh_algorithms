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
typedef pair<int, int> PII;
class Solution {
public:
    bool canMeasureWater(int C1,int C2,int T) {
        stack<PII> st;
        st.emplace(0,0);
        unordered_set<pair<int,int>,HashFunc,EqualKey> hset;    //用哈希集合判断状态重复
        hset.insert(PII(0,0));
        while (!st.empty()) {
            auto [cap1,cap2]=st.top();st.pop();
            if (cap1==T || cap2==T || cap1+cap2==T)
                return true;
            if(hset.count(PII(C1,cap2))==0) {      //壶1装满
                hset.insert(PII(C1,cap2));
                st.emplace(C1,cap2);
            }
            if(hset.count(PII(cap1,C2))==0) {      //壶2装满
                hset.insert(PII(cap1,C2));
                st.emplace(cap1,C2);
            }
             if(hset.count(PII(0,cap2))==0) {      //壶1清空
                hset.insert(PII(0,cap2));
                st.emplace(0,cap2);
             }
             if(hset.count(PII(cap1,0))==0) {      //壶2清空
                hset.insert(PII(cap1,0));
                st.emplace(cap1,0);
             }
            int need=min(cap1,C2-cap2);                  //取壶1和壶2剩余空间的最小值
            if(hset.count(PII(cap1-need,cap2+need))==0) {
                hset.insert(PII(cap1-need,cap2+need));  //将壶1中的need水倒入壶2
                st.emplace(cap1-need,cap2+need);
            }
            need=min(cap2,C1-cap1);                  //取壶2和壶1剩余空间的最小值
            if(hset.count(PII(cap1+need,cap2-need))==0) {
                hset.insert(PII(cap1+need,cap2-need));  //将壶2中的need水倒入壶1
                st.emplace(cap1+need,cap2-need);
            }
        }
        return false;
    }
};

