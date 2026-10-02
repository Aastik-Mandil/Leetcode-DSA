class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> s;
        vector<string> rows;
        unordered_map<string, unordered_map<string, int>> dishCountPerUser; // {user_id: {dish_name: count}}
        for(int i=0; i<orders.size(); i++){
            if(find(rows.begin(), rows.end(), orders[i][1]) == rows.end()){
                rows.push_back(orders[i][1]);
            }
            for(int j=2; j<orders[i].size(); j++){
                dishCountPerUser[orders[i][1]][orders[i][j]]++;
                s.insert(orders[i][j]);
            }
        }

        vector<vector<string>> ans;
        vector<string> header;
        for(auto itr=s.begin(); itr!=s.end(); itr++){
            header.push_back(*itr);
        }

        for(int i=0; i<rows.size(); i++){
            ans.push_back({rows[i]});
            for(int j=0; j<header.size(); j++){
                ans.back().push_back(
                    to_string(dishCountPerUser[rows[i]][header[j]])
                );
            }
        }
        sort(ans.begin(), ans.end(), [](vector<string> &a, vector<string> &b){
            return stoi(a[0]) < stoi(b[0]);
        });
        header.insert(header.begin(), "Table");
        ans.insert(ans.begin(), header);

        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/description/
