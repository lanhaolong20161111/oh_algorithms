class KthLargest {
    priority_queue<int,vector<int>,greater<int>> minpq;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {      //初始化
        int n=nums.size();
        K=k;
        if(n<k) {
            for(int i=0;i<n;i++)    //n<k时全部元素进堆(依题意,n至少为k-1)
                minpq.push(nums[i]);
        }
        else {                      //n>=k时将最大的k个元素进堆
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
    int add(int val) {                 		//添加一个元素val
        if(minpq.size()==K-1)           	//有K-1个元素(依题意,插入val之前至少有K-1个元素)
            minpq.push(val);
        else{									//有K个元素(由小根堆的维护操作实现的)
            if(minpq.top()<val) {       	//有K个元素时
                minpq.pop();
                minpq.push(val);
            }
        }
        return minpq.top();
    }
};

