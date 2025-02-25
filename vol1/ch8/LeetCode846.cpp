class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n=hand.size();
        if(n%k!=0) return false;
        map<int,int> tmap;
        for(int i=0;i<n;i++) tmap[hand[i]]++;
        while(!tmap.empty()) {
            auto it=tmap.begin();      //遍历tmap
            int x=it->first;
            for(int i=0;i<k;i++) {      //找连续的k个数字
                if(it->first!=x+i)      //没有找到返回false
                    return false;
                it->second--;           //将it指向数字个数减1
                if(it->second==0)       //数字个数为0时从tmap中删除该元素
                    tmap.erase(it);
                it++;
            }
        }
        return true;
    }
};

