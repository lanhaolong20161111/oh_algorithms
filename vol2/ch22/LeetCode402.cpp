class Solution {
public:
    string removeKdigits(string num,int k) {
        int n=num.size();
        if (n<=k) return "0";
        int i=0;
        while (k>0) {                   //在num中删除k位
            while(i<n-1 && num[i]<=num[i+1])
                i++;                    //找一个递减(含相同元素)区间
            num.erase(i,1);             //删除该递减区间元素num[i]
            k--;
            n--;
            if(i>0) i--;    //非首字符时
        }
        while (num.size()>1 && num[0]=='0')     //删除前导0
                num.erase(0,1);
        return num;
    }
};

