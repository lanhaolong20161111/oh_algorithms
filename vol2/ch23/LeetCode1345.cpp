struct QNode{                    //队列中结点类型
    int p;							//位置
    int steps;						//最少跳跃次数
    QNode(int p,int s):p(p),steps(s) {}
};
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>> hmap;
        for (int i=0;i<n;i++)       //将数组元素值相同的下标放在hmap中
            hmap[arr[i]].push_back(i);
        unordered_set<int> visited;
        queue<QNode> qu;
        qu.push(QNode(0,0));
        visited.insert(0);
        while(!qu.empty()) {
            QNode e=qu.front();qu.pop();
            int p=e.p,steps=e.steps;
            if(p==n-1) return steps;				//找到目标，返回steps
            int v=arr[p];
            if(hmap.count(v)) {					//处理跳跃方式（3）
                for (auto &i:hmap[v]) {
                    if(!visited.count(i)) {
                        visited.insert(i);
                        qu.push(QNode(i,steps+1));
                    }
                }
                hmap.erase(v);						//从hmap中删除(v,*)以提高性能
            }
            int p1=p+1;									//处理跳跃方式（1）
            if (p1<n && !visited.count(p1)) {
                visited.insert(p1);
                qu.push(QNode(p1,steps+1));
            }
            int p2=p-1;									//处理跳跃方式（2）
            if (p2>=0 && !visited.count(p2)) {
                visited.insert(p2);
                qu.push(QNode(p2,steps+1));
            }
        }
        return -1;
    }
};

