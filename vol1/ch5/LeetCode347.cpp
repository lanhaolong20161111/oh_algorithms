struct PNode {                                  //优先队列元素类型：可以用pair代替
    int key;                                                                //关键字
        int cnt;                                                                //出现的次数
        PNode(int k,int c):key(k),cnt(c) {}
        bool operator<(const PNode &s) const {                  //重载<关系函数
        return cnt>s.cnt;                                       //按cnt越小越优先
        }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums,int k) {
        unordered_map<int,int> hmap;
            vector<int> ans;
            priority_queue<PNode> minpq;
            for(int i=0;i<nums.size();i++)                          //用hmap累计每个整数出现的次数
                hmap[nums[i]]++;
        for(auto x:hmap) {      //遍历hmap
            if(minpq.size()<k)                                      //进队k个整数
                    minpq.push(PNode(x.first,x.second));
                else {                                          //处理剩余的整数
                    if(minpq.top().cnt<x.second) {
                    minpq.pop();
                    minpq.push(PNode(x.first,x.second));
                    }
                }
        }
        while(!minpq.empty()) {                                     //出队所有整数
            ans.push_back(minpq.top().key);
            minpq.pop();
        }
            return ans;
        }
};

