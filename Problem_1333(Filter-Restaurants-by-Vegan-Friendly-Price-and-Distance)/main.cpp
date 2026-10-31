bool cond(vector<int> &a, vector<int> &b){
    if(a[1] == b[1]){
        return a[0] > b[0];
    }
    return a[1] > b[1];
}

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        // sort based on rating (desc), if same raing then id (desc)
        sort(restaurants.begin(), restaurants.end(), cond);

        vector<int> ans;
        for(vector<int> &restaurant: restaurants){
            int id = restaurant[0];
            int rating = restaurant[1];
            int vegan = restaurant[2];
            int price = restaurant[3];
            int distance = restaurant[4];

            // check cnditions
            if(veganFriendly == 1 && vegan == 0){
                continue;
            }
            if(maxPrice < price || maxDistance < distance){
                continue;
            }
            ans.push_back(id);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/description/
