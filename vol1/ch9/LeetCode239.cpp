struct QNode {                                      //优先队列元素类型
    int i;                                          //元素序号
    int val;                                        //元素值
    QNode() {}
    QNode(int i,int v):i(i),val(v) {}
    bool operator<(const QNode&s) const {
        return val<s.val;                          //按val越大越优先出队
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<QNode> maxpq;             //大根堆
        vector<int> ans;
        for (int i=0;i<n;i++) {
            while (!maxpq.empty() && i-maxpq.top().i>=k)
                maxpq.pop();                   			 //将所有过期的堆顶元素出队
            maxpq.push(QNode(i,nums[i]));
            if (i>=k-1)
                ans.push_back(maxpq.top().val);
        }
        return ans;
    }
};

