struct FOOD {
    int rat;              //评分 
    string cuis;          //烹饪方式
};

struct CUISINES {
    int rat;              //评分
    string food;          //食物
    bool operator<(const CUISINES&s) const {     //按评分递减，食物递增顺序
        if(rat!=s.rat) return rat>s.rat;
        else return food<s.food;
    }
};

class FoodRatings {
public:
    unordered_map<string,FOOD> foodhmap;       //以食物为键
    unordered_map<string,set<CUISINES>> cuishmap;   //以烹饪方式为键
    FoodRatings(vector<string>& foods,vector<string>& cuisines,vector<int>&ratings) {
        for(int i=0;i<foods.size();i++) {							//遍历食物的数据
            foodhmap[foods[i]]={ratings[i],cuisines[i]};
            cuishmap[cuisines[i]].insert({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &p=foodhmap[food];
        cuishmap[p.cuis].erase({p.rat,food});				//删除cuishmap[p.cuis]中原评分
        p.rat=newRating;											//修改foodhmap[food]的评分
        cuishmap[p.cuis].insert({newRating,food});		//插入cuishmap[p.cuis]的新评分
    }

    string highestRated(string cuisine) {
        auto  i=cuishmap[cuisine].begin();					//返回cuishmap[cuisine]首元素的food
        return i->food;
    }
};

