class MovieRentingSystem {
public:
    set<pair<int,int>> mvset[10010];     //按电影编号存放<商店,价格>(未借出)
    set<pair<int,pair<int,int>>> rentset;  //按价格递增存放所有借出的<商店,电影>
    map<pair<int,int>,int> prcmap;          //存放<商店,电影>的价格
    MovieRentingSystem(int n,vector<vector<int>>& entries) {
        for (int i=0;i<entries.size();i++) {					//遍历entries进行初始化
            int x=entries[i][0], y=entries[i][1], z=entries[i][2];
            prcmap[make_pair(x,y)]=z;
            mvset[y].insert(make_pair(z,x));				//此时所有电影均没有借出
        }
    }
    
    vector<int> search(int movie) {
        auto it=mvset[movie].begin();
        vector<int> ans;
        for (int i=0;i<5 && it!=mvset[movie].end();i++,it++)	//在mvset[movie]中查找
            ans.push_back(it->second);		//在mvset[movie]中从后向前找最多5部电影
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price=prcmap[make_pair(shop, movie)];			//找到对应的价格
        mvset[movie].erase(make_pair(price, shop));		//从未借库中删除
        rentset.insert(make_pair(price, make_pair(shop, movie)));	//将其添加到借出库中
    }
    
    void drop(int shop, int movie) {
        int price=prcmap[make_pair(shop, movie)];			//找到对应的价格
        rentset.erase(make_pair(price, make_pair(shop, movie)));	//从借出库中删除
        mvset[movie].insert(make_pair(price, shop));		//将其添加到未借库中
    }
    
    vector<vector<int>> report() {
        auto it=rentset.begin();
        vector<vector<int>> ans;
        for (int i=0;i<5 && it!=rentset.end();i++,it++)		//在借出库中顺序查找
            ans.push_back({(it->second).first, (it->second).second});
        return ans;
    }
};

