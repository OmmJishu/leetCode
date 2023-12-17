class FoodRatings {
    private:
    struct comp {
        bool operator()(const pair<int, string> &a, const pair<int, string> &b) const {
            if (a.first != b.first)
                return a.first > b.first;
            else
                return a.second < b.second;
        }
    };

public:
    unordered_map<string,set<pair<int,string>, comp>> cuisinToFood;
    unordered_map<string,string> foodToCuisin;
    unordered_map<string,int> foodRating;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i<foods.size(); i++){
            cuisinToFood[cuisines[i]].insert({ratings[i],foods[i]});
            foodToCuisin[foods[i]] = cuisines[i];
            foodRating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string getCuisin = foodToCuisin[food];
        int currRating = foodRating[food];
        
        foodRating[food] = newRating;
        cuisinToFood[getCuisin].erase({currRating,food});
        cuisinToFood[getCuisin].insert({newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto it = *(cuisinToFood[cuisine].begin());
        return it.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */