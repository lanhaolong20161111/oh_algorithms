class ExamRoom {
    set<int> tset;
    int start,end;
public:
    ExamRoom(int n) {
        start=0;
        end=n-1;
    }
    
    int seat() {
        int ans=start,pre=start;
        int maxdist=(tset.empty()?end:*tset.begin())-start;
        for(int e:tset) {
            if(maxdist<(e-pre)/2) {
                maxdist=(e-pre)/2;
                ans=pre+maxdist;
            }
            pre=e;
        }
        if(maxdist<end-pre)
            ans=end;
        tset.insert(ans);
        return ans;
    }
    
    void leave(int p) {
        tset.erase(p);
    }
};

