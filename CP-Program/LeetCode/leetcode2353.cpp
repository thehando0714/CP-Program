class FoodRatings {
public:
    map<string,set<pair<int,string>>>foodInfo;
    map<string, pair<string,int>> foodInfoExtra;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            auto it=make_pair(ratings[i]*-1,foods[i]);
            foodInfo[cuisines[i]].insert(it);
            auto it2=make_pair(cuisines[i],ratings[i]);
            foodInfoExtra[foods[i]]=it2;
        }
    }
    
    void changeRating(string food, int newRating) {
        auto tmp = foodInfoExtra[food];
        string cuisine = tmp.first;
        int old = tmp.second;
        foodInfo[cuisine].erase({-old,food});
        foodInfo[cuisine].insert({-newRating,food});
        foodInfoExtra[food]={cuisine,newRating};
    }
    
    string highestRated(string cuisine) {
        
       return foodInfo[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */