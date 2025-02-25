struct QNode {
    int i;                  //��ʾnums1[i]�����
    int j;                  //��ʾnums2[j]�����
    int sum;                //��ʾnums1[i]+nums2[j]
    QNode() {}
    QNode(int i,int j,int s):i(i),j(j),sum(s) {}
    bool operator<(const QNode&s) const {
        return sum>s.sum;   //��sumԽСԽ���ȳ���
    }
};
class Solution {
    const int INF=0x3f3f3f3f;
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1,vector<int>& nums2,int k) {
        int m=nums1.size();
        int n=nums2.size();
        vector<vector<int>> ans;
        priority_queue<QNode> minpq;
        for(int i=0;i<m;i++)                    //�������0-n-1����Ԫ�ؽ���
            minpq.push(QNode(i,0,nums1[i]+nums2[0]));
        while(k-- && !minpq.empty()) {          //ѭ��k�λ��߶ӿ�Ϊֹ
            QNode e=minpq.top(); minpq.pop();   //����Ԫ��e
            ans.push_back({nums1[e.i],nums2[e.j]});
            if(e.j+1<n)                         //�����e.iû�г���ʱ
                minpq.push(QNode(e.i,e.j+1,nums1[e.i]+nums2[e.j+1]));
        }
        return ans;
    }
};

