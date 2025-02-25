class Solution {
public:
    int countStudents(vector<int>& students,vector<int>& sandwiches) {
        queue<int> qu;
        for (int stud:students) {
            qu.push(stud);
        }
        int i=0;                //����������
        int cnt=0;              //һ�����ۼƱȽϵĴ���
        while (!qu.empty()) {
            if (cnt==qu.size()) //ѧ������ÿ��ѧ�����Ƚ�һ�Σ������
                return qu.size();
            int stud=qu.front(); qu.pop();
            if (stud==sandwiches[i]) {  //�Ƚϳɹ�
                i++;                    //�Ƶ���һ��������
                cnt=0;                  //��ʼ��һ��
            }
            else {                      //�Ƚϲ�����
                qu.push(stud);          //ѧ�������β
                cnt++;                  //���ֱȽϴ�����1
            }
        }
        return 0;
    }
};

