struct QNode {                                      //���ȶ���Ԫ������
    int i;                                          //Ԫ�����
    int val;                                        //Ԫ��ֵ
    QNode() {}
    QNode(int i,int v):i(i),val(v) {}
    bool operator<(const QNode&s) const {
        return val<s.val;                          //��valԽ��Խ���ȳ���
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<QNode> maxpq;             //�����
        vector<int> ans;
        for (int i=0;i<n;i++) {
            while (!maxpq.empty() && i-maxpq.top().i>=k)
                maxpq.pop();                   			 //�����й��ڵĶѶ�Ԫ�س���
            maxpq.push(QNode(i,nums[i]));
            if (i>=k-1)
                ans.push_back(maxpq.top().val);
        }
        return ans;
    }
};

