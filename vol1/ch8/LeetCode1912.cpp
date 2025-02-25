class MovieRentingSystem {
public:
    set<pair<int,int>> mvset[10010];     //����Ӱ��Ŵ��<�̵�,�۸�>(δ���)
    set<pair<int,pair<int,int>>> rentset;  //���۸����������н����<�̵�,��Ӱ>
    map<pair<int,int>,int> prcmap;          //���<�̵�,��Ӱ>�ļ۸�
    MovieRentingSystem(int n,vector<vector<int>>& entries) {
        for (int i=0;i<entries.size();i++) {					//����entries���г�ʼ��
            int x=entries[i][0], y=entries[i][1], z=entries[i][2];
            prcmap[make_pair(x,y)]=z;
            mvset[y].insert(make_pair(z,x));				//��ʱ���е�Ӱ��û�н��
        }
    }
    
    vector<int> search(int movie) {
        auto it=mvset[movie].begin();
        vector<int> ans;
        for (int i=0;i<5 && it!=mvset[movie].end();i++,it++)	//��mvset[movie]�в���
            ans.push_back(it->second);		//��mvset[movie]�дӺ���ǰ�����5����Ӱ
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price=prcmap[make_pair(shop, movie)];			//�ҵ���Ӧ�ļ۸�
        mvset[movie].erase(make_pair(price, shop));		//��δ�����ɾ��
        rentset.insert(make_pair(price, make_pair(shop, movie)));	//������ӵ��������
    }
    
    void drop(int shop, int movie) {
        int price=prcmap[make_pair(shop, movie)];			//�ҵ���Ӧ�ļ۸�
        rentset.erase(make_pair(price, make_pair(shop, movie)));	//�ӽ������ɾ��
        mvset[movie].insert(make_pair(price, shop));		//������ӵ�δ�����
    }
    
    vector<vector<int>> report() {
        auto it=rentset.begin();
        vector<vector<int>> ans;
        for (int i=0;i<5 && it!=rentset.end();i++,it++)		//�ڽ������˳�����
            ans.push_back({(it->second).first, (it->second).second});
        return ans;
    }
};

