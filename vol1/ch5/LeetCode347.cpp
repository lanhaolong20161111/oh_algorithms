struct PNode {                                  //���ȶ���Ԫ�����ͣ�������pair����
    int key;                                                                //�ؼ���
        int cnt;                                                                //���ֵĴ���
        PNode(int k,int c):key(k),cnt(c) {}
        bool operator<(const PNode &s) const {                  //����<��ϵ����
        return cnt>s.cnt;                                       //��cntԽСԽ����
        }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums,int k) {
        unordered_map<int,int> hmap;
            vector<int> ans;
            priority_queue<PNode> minpq;
            for(int i=0;i<nums.size();i++)                          //��hmap�ۼ�ÿ���������ֵĴ���
                hmap[nums[i]]++;
        for(auto x:hmap) {      //����hmap
            if(minpq.size()<k)                                      //����k������
                    minpq.push(PNode(x.first,x.second));
                else {                                          //����ʣ�������
                    if(minpq.top().cnt<x.second) {
                    minpq.pop();
                    minpq.push(PNode(x.first,x.second));
                    }
                }
        }
        while(!minpq.empty()) {                                     //������������
            ans.push_back(minpq.top().key);
            minpq.pop();
        }
            return ans;
        }
};

