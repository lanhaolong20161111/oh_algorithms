class Solution {
public:
    int countStudents(vector<int>& students,vector<int>& sandwiches) {
        queue<int> qu;
        for (int stud:students) {
            qu.push(stud);
        }
        int i=0;                //遍历三明治
        int cnt=0;              //一轮中累计比较的次数
        while (!qu.empty()) {
            if (cnt==qu.size()) //学生队中每个学生都比较一次，则结束
                return qu.size();
            int stud=qu.front(); qu.pop();
            if (stud==sandwiches[i]) {  //比较成功
                i++;                    //移到下一个三明治
                cnt=0;                  //开始下一轮
            }
            else {                      //比较不超过
                qu.push(stud);          //学生进入队尾
                cnt++;                  //本轮比较次数增1
            }
        }
        return 0;
    }
};

