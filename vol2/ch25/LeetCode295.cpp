class MedianFinder {
    priority_queue<int,vector<int>,greater<int>> minpq; //����һ��С����
    priority_queue<int> maxpq;                            //����һ�������
public:
    MedianFinder() {  }
    
    void addNum(int num) {
        if(minpq.empty()) {                                   //��С���ѿ�
           minpq.push(num);
            return;
        }
        if(num>minpq.top())                                 //��x����С���ѶѶ�Ԫ��
            minpq.push(num);                                //��x���뵽С������
        else
            maxpq.push(num);                                  //����x���뵽�������
        if(minpq.size()<maxpq.size()) {                     //��С����Ԫ�ظ�������
           minpq.push(maxpq.top());
            maxpq.pop();                                  //ȡ������ѶѶ�Ԫ�ز��뵽С������
        }
        if(minpq.size()-maxpq.size()>1) {                   //��С���ѱȴ�������ٶ�2��Ԫ��
           maxpq.push(minpq.top());
            minpq.pop();                            //ȡ��С���ѵĶѶ�Ԫ�ز��뵽�������
        }
    }
   
    double findMedian() {
        if (minpq.size()==maxpq.size())
            return (minpq.top()+maxpq.top())/2.0;
	else
            return minpq.top();
    }
};

