class Solution {
public:
    string decodeString(string s) {
        int i=0;                            //i��0��ʼ����s
        return unfold(s,i);
    }
    string unfold(string&s,int& i) {       //�ݹ��㷨
        int n=s.size();
        string ans="";                      //����ַ������� 
        while(i<n) {                        //����s
            if(isalpha(s[i])) {             //������ĸ
                ans+=s[i++];                //��ȡ��������ĸ��
            }
            else if(isdigit(s[i])) {        //��������
                int k=0;
                while(i<n && isdigit(s[i])) {
                    k=10*k+(s[i++]-'0');    //�������֣������������ַ�ת��Ϊ����k
                }
                i++;                        //���������'['
                string d=unfold(s,i);       //�ݹ�չ��������(e)�õ�d
                while(k--) {                  //����d�ַ���k��
                    ans+=d;
                }
            }
            else {                          //����']'
                i++;                        //����']'
                return ans;                 //���ظ�����Ľ�
            }
        }
        return ans;
    }
};

