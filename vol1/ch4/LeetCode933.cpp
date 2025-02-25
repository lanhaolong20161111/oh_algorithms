class RecentCounter {
    queue<int> qu;
public:
    RecentCounter() { }

    int ping(int t) {
        qu.push(t);
        while(qu.front()<t-3000)
            qu.pop();
        return qu.size();
     }
};

