class MedianFinder {
    priority_queue<int,vector<int>,greater<int>> minpq; //定义一个小根堆
    priority_queue<int> maxpq;                            //定义一个大根堆
public:
    MedianFinder() {  }
    
    void addNum(int num) {
        if(minpq.empty()) {                                   //若小根堆空
           minpq.push(num);
            return;
        }
        if(num>minpq.top())                                 //若x大于小根堆堆顶元素
            minpq.push(num);                                //将x插入到小根堆中
        else
            maxpq.push(num);                                  //否则将x插入到大根堆中
        if(minpq.size()<maxpq.size()) {                     //若小根堆元素个数较少
           minpq.push(maxpq.top());
            maxpq.pop();                                  //取出大根堆堆顶元素插入到小根堆中
        }
        if(minpq.size()-maxpq.size()>1) {                   //若小根堆比大根堆至少多2个元素
           maxpq.push(minpq.top());
            minpq.pop();                            //取出小根堆的堆顶元素插入到大根堆中
        }
    }
   
    double findMedian() {
        if (minpq.size()==maxpq.size())
            return (minpq.top()+maxpq.top())/2.0;
	else
            return minpq.top();
    }
};

