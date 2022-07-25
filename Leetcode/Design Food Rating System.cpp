struct cmp{
  bool operator()(pair<int,string> p1,pair<int,string> p2)const{
      if(p1.first==p2.first)
          return p1.second<p2.second;
      return p1.first>p2.first;
  }  
};

class FoodRatings {
public:
    unordered_map<string,int> mp; //food->rating
    unordered_map<string,string> mp2; //food->cuisines
    unordered_map<string,set<pair<int,string>,cmp>> raFood; //cuisines->pair<rating,food>
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        for(int i=0;i<foods.size();i++){
            mp[foods[i]]=ratings[i];
            mp2[foods[i]]=cuisines[i];
            raFood[cuisines[i]].insert({ratings[i],foods[i]});
        }
        
    }
    
    void changeRating(string food, int newRating) {
        auto it=raFood[mp2[food]].find({mp[food],food});
        raFood[mp2[food]].erase(it);
        raFood[mp2[food]].insert({newRating,food});
        mp[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        
        return raFood[cuisine].begin()->second;
        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */