template <typename T>
bool cmp(T a,T b) {     //用于创建大根堆
    return a<b;
}
template <typename T>
class Heap {                                    //堆数据结构的实现
    int n;                                  //堆中元素个数
    vector<T> R;                            //用R[0..n-1]存放堆中元素
    void siftDown(int low,int high) {       //R[low..high]的自顶向下筛选
        int i=low;
        int j=2*i+1;                            //R[j]是R[i]的左孩子
        T tmp=R[i];                         //tmp临时保存根结点
        while (j<=high) {                   //只对R[low..high]的元素进行筛选
            if (j<high && cmp(R[j],R[j+1]))
                j++;                            //若右孩子较大,把j指向右孩子
            if (cmp(tmp,R[j])) {                    //tmp的孩子较大
                R[i]=R[j];                  //将R[j]调整到双亲位置上
                i=j; j=2*i+1;                   //修改i和j值,以便继续向下筛选
            }
            else break;                     //若孩子较小，则筛选结束
        }
        R[i]=tmp;                           //原根结点放入最终位置
    }
    void siftUp(int j) {                        //自底向上筛选:从叶子结点j向上筛选
        int i=(j-1)/2;                          //i指向R[j]的双亲
        T tmp=R[j];
        while (j!=0) { 
            if (cmp(R[i],tmp)) {                    //若孩子较大，则交换
                R[j]=R[i];
                j=i; i=(j-1)/2;
            }
            else break;                 //到达根结点时结束
        }
        R[j]=tmp;
    }
public:
    Heap():n(0) {}                          //构造函数
    void push(T e) {                                //插入元素e
        R.push_back(e);                     //将e添加到末尾
        n++;                                    //堆中元素个数增1
        if (n==1) return;                           //e作为根结点的情况
        int j=n-1;
        siftUp(j);                              //从叶子结点R[j]向上筛选
    }
    T pop() {                               //删除堆顶元素
        T e=R[0];                           //取出堆顶元素
        R[0]=R[n-1];                        //用尾元素覆盖R[0]
        R.pop_back();
        n--;                                    //元素个数减少1
        if(n>1) 
        	siftDown(0,n-1);                        //筛选为一个堆
        return e;
    }
    T top() {                               //取堆顶元素
        return R[0];
    }
    bool empty() {                          //判断堆是否为空
        return n==0;
    }
};

struct QNode {          //优先队列元素类型
    int sc;             //分数
    int i;              //初始位置
    QNode() {}
    QNode(int sc,int i):sc(sc),i(i) {}
    bool operator<(const QNode &s) const    {           //重载<关系函数
        return sc<s.sc;     //按sc越大越优先
    }
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string> ans(score.size());
        Heap<QNode>  pq;               //大根堆
        for(int i=0;i<n;i++) {
            pq.push(QNode(score[i],i));
        }
        int i=1;
        while(!pq.empty()){
            QNode e=pq.top(); pq.pop();
            if(i==1) ans[e.i]="Gold Medal";
            else if(i==2) ans[e.i]="Silver Medal";
            else if(i==3) ans[e.i]="Bronze Medal";
            else ans[e.i]=to_string(i);
            i++;
        }
        return ans;
    }
};

