class Solution {
public:
    void reverseString(vector<char>& s) {
        rev(s,0,s.size()-1);
    }
    void rev(vector<char>&s,int i,int j) {
        if(i<j) {       											//���ٺ������ַ�
            swap(s[i],s[j]);
            rev(s,i+1,j-1);
        }
    }
};

