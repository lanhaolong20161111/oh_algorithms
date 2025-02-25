class Solution {
public:
    string removeKdigits(string num,int k) {
        int n=num.size();
        if (n<=k) return "0";
        int i=0;
        while (k>0) {                   //��num��ɾ��kλ
            while(i<n-1 && num[i]<=num[i+1])
                i++;                    //��һ���ݼ�(����ͬԪ��)����
            num.erase(i,1);             //ɾ���õݼ�����Ԫ��num[i]
            k--;
            n--;
            if(i>0) i--;    //�����ַ�ʱ
        }
        while (num.size()>1 && num[0]=='0')     //ɾ��ǰ��0
                num.erase(0,1);
        return num;
    }
};

