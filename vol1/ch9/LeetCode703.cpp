class KthLargest {
    priority_queue<int,vector<int>,greater<int>> minpq;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {      //��ʼ��
        int n=nums.size();
        K=k;
        if(n<k) {
            for(int i=0;i<n;i++)    //n<kʱȫ��Ԫ�ؽ���(������,n����Ϊk-1)
                minpq.push(nums[i]);
        }
        else {                      //n>=kʱ������k��Ԫ�ؽ���
            for(int i=0;i<k;i++)
                minpq.push(nums[i]);
            for(int i=k;i<n;i++) {
                if(minpq.top()<nums[i]) {
                    minpq.pop();
                    minpq.push(nums[i]);
                }
            }
        }
    }
    int add(int val) {                 		//���һ��Ԫ��val
        if(minpq.size()==K-1)           	//��K-1��Ԫ��(������,����val֮ǰ������K-1��Ԫ��)
            minpq.push(val);
        else{									//��K��Ԫ��(��С���ѵ�ά������ʵ�ֵ�)
            if(minpq.top()<val) {       	//��K��Ԫ��ʱ
                minpq.pop();
                minpq.push(val);
            }
        }
        return minpq.top();
    }
};

