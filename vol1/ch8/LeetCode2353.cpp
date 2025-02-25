struct FOOD {
    int rat;              //���� 
    string cuis;          //��⿷�ʽ
};

struct CUISINES {
    int rat;              //����
    string food;          //ʳ��
    bool operator<(const CUISINES&s) const {     //�����ֵݼ���ʳ�����˳��
        if(rat!=s.rat) return rat>s.rat;
        else return food<s.food;
    }
};

class FoodRatings {
public:
    unordered_map<string,FOOD> foodhmap;       //��ʳ��Ϊ��
    unordered_map<string,set<CUISINES>> cuishmap;   //����⿷�ʽΪ��
    FoodRatings(vector<string>& foods,vector<string>& cuisines,vector<int>&ratings) {
        for(int i=0;i<foods.size();i++) {							//����ʳ�������
            foodhmap[foods[i]]={ratings[i],cuisines[i]};
            cuishmap[cuisines[i]].insert({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &p=foodhmap[food];
        cuishmap[p.cuis].erase({p.rat,food});				//ɾ��cuishmap[p.cuis]��ԭ����
        p.rat=newRating;											//�޸�foodhmap[food]������
        cuishmap[p.cuis].insert({newRating,food});		//����cuishmap[p.cuis]��������
    }

    string highestRated(string cuisine) {
        auto  i=cuishmap[cuisine].begin();					//����cuishmap[cuisine]��Ԫ�ص�food
        return i->food;
    }
};

