struct QNode {
    int i;                  //表示nums1[i]的序号
    int j;                  //表示nums2[j]的序号
    int sum;                //表示nums1[i]+nums2[j]
    QNode() {}
    QNode(int i,int j,int s):i(i),j(j),sum(s) {}
    bool operator<(const QNode&s) const {
        return sum>s.sum;   //按sum越小越优先出队
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
        for(int i=0;i<m;i++)                    //将有序段0-n-1的首元素进队
            minpq.push(QNode(i,0,nums1[i]+nums2[0]));
        while(k-- && !minpq.empty()) {          //循环k次或者队空为止
            QNode e=minpq.top(); minpq.pop();   //出队元素e
            ans.push_back({nums1[e.i],nums2[e.j]});
            if(e.j+1<n)                         //有序段e.i没有超界时
                minpq.push(QNode(e.i,e.j+1,nums1[e.i]+nums2[e.j+1]));
        }
        return ans;
    }
};

