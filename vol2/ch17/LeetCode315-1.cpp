struct IDX {
    int val;                                        //整数
    int idx;                                        //整数在nums中的下标
    IDX() {}                                        //构造函数
    IDX(int v,int i):val(v),idx(i) {}               //重载构造函数 
};
class Solution {
    vector<int> counts;                         //存放结果的数组
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<IDX> a;                              //a存放每个元素及其索引
        for (int i=0;i<n;i++) {
            a.push_back(IDX(nums[i],i));            //a保存每个元素中及其下标 
            counts.push_back(0);                    //初始化counts所有元素为0 
        }
        mergesort(a,0,n-1);
        return counts;
    }
    void mergesort(vector<IDX>&a,int low,int high) {   //二路归并排序
        if (low<high) {
            int mid=(low+high)/2;
            mergesort(a,low,mid);
            mergesort(a,mid+1,high);
            merge(a,low,mid,high);
        }
    }
    void merge(vector<IDX>&a,int low,int mid,int high) {        //二路归并
        int i=low,j=mid+1;                         //二路归并
        vector<IDX> tmp;                           //分配临时归并空间tmp
        while (i<=mid && j<=high) {
            if (a[i].val<=a[j].val) {         //a[i]元素较小
                tmp.push_back(a[i]);           //归并a[i]
                counts[a[i].idx]+=j-mid-1;     //累加a[i]位置前移的元素个数
                i++;
            }
            else {                                  //a[j]元素较小
                tmp.push_back(a[j]);                     //归并a[j]
                j++;
            }
        }
        while (i<=mid) {                                        //第1个段没有遍历完
            tmp.push_back(a[i]);
            counts[a[i].idx]+=high-mid;
            i++;
        }
        while (j<=high) {                                       //第2个段没有遍历完
            tmp.push_back(a[j]);
            j++;
        }
        for (int j=0,i=low;i<=high;j++,i++)          //将tmp复制回a中
            a[i]=tmp[j];
    }
};

