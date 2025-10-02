class MovieRentingSystem {
public:
    map<pair<int,int>,int>info;//shop movie price;
    set<pair<int,pair<int,int>>>rented;//for report  price,shop,movie
    map<int,set<pair<int,int>>>forSearch;//unrented   movie,price,shop
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(int i=0;i<entries.size();i++){
            auto it=make_pair(entries[i][0],entries[i][1]);
            info[it]=entries[i][2];
            auto it2=make_pair(entries[i][2],entries[i][0]);
            forSearch[entries[i][1]].insert(it2);
        }
    }
    
    vector<int> search(int movie) {
        vector<int>ans;
        if(forSearch[movie].size()==0){
            return ans;
        }
        for(auto it=forSearch[movie].begin();it!=forSearch[movie].end();it++){
            if(ans.size()==5){
                break;
            }
            ans.push_back(it->second);
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price=info[{shop,movie}];
        rented.insert({price,{shop,movie}});
        forSearch[movie].erase({price,shop});
    }
    
    void drop(int shop, int movie) {
        int price=info[{shop,movie}];
        rented.erase({price,{shop,movie}});
        forSearch[movie].insert({price,shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>ans;
        if(rented.size()==0){
            return ans;
        }
        for(auto it=rented.begin();it!=rented.end();it++){
            if(ans.size()==5){
                break;
            }
            vector<int>tmp={it->second.first,it->second.second};
            ans.push_back(tmp);    
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */